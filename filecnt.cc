#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void DisplayDirectoryTree(const fs::path&, long long int&, int&, int&, int);

int main(int argc, char** argv)
{
	if (argc <= 1) {
		std::cout << "Invalid option given!" << std::endl;
		return 0;
	}

	const fs::path pathToShow{ argc >= 2 ? argv[1] : fs::current_path() };

	long long int numBytes = 0;
	int numDir=0, numFiles=0;
	DisplayDirectoryTree(pathToShow, numBytes, numDir, numFiles, 0);

	std::cout << "The total number of directories in directory "
		<< pathToShow << " is: " << numDir << "."  << std::endl;

	std::cout << "The total number of files in directory "
		<< pathToShow << " is: " << numFiles << "." << std::endl;

	std::cout << "The total number of bytes occupied by all files "
		<< "in directory " << pathToShow
		<< " is: " << numBytes << "." << std::endl;

	return 0;
}

void DisplayDirectoryTree(const fs::path& pathToScan, long long int &numBytes, int &numDir, int &numFiles, int level = 0) {
	for (const auto& entry : fs::directory_iterator(pathToScan)) {
		const auto filenameStr = entry.path().filename().string();
		if (entry.is_directory()) {
			DisplayDirectoryTree(entry, numBytes, numDir, numFiles, level+1);
			numDir++;
		}
		else if (entry.is_regular_file()) {
			numFiles++;
			numBytes += entry.file_size();
		}
	}
}
