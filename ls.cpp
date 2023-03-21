#include <iostream>
#include <filesystem>

void print_current_directory(const std::filesystem::path &path);

// Trivial implementation of ls 
int main(int argc, char* argv[]) {

  std::filesystem::path path;

  if (argc == 1) {

    path = std::filesystem::path(".");
    print_current_directory(path);

  } else {



    if (argc == 2) {
      path = std::filesystem::path(argv[1]);
      print_current_directory(path);

    } else {

      int current_argument = 1;
      int counter = 1;

      while (counter < argc) {
	std::cout << argv[current_argument] << ":\n";
	print_current_directory(argv[current_argument]);
	current_argument++;
	counter++;
      }

    }
  }

  return 0;
}

void print_current_directory(const std::filesystem::path &path) {
	for (auto const& dir_entry : std::filesystem::directory_iterator{path}) {
	  std::cout << dir_entry << "\n";
	}

}
