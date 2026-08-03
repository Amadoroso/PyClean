# PyClean

A lightweight, interactive Python utility designed to recursively find and purge Python bytecode (`__pycache__`) and static type-checker caches (`.mypy_cache`) from your project directories.

## Mechanics

Unlike standard shell commands (`find` + `rm -rf`), this script is entirely OS-independent. It uses Python's built-in libraries to safely handle directory traversal and removal:
* **`pathlib.Path.rglob`**: Recursively searches the current working directory for target cache folders using generator objects for memory efficiency.
* **`shutil.rmtree`**: Safely forces the deletion of directories and all their internal contents.

## Usage

Run the script from the root of the directory you want to clean:

```bash
python3 ft_pyclean.py

```

### Execution Flow

1. The script will prompt you with an interactive `[y/n]` confirmation to prevent accidental deletions.
2. If confirmed, it chains the search generators.
3. It prints a color-coded log of every directory removed.
4. It outputs the total number of cleaned cache folders.

## Requirements

* Python 3.x
* No external libraries or pip installations required (strictly uses standard built-ins: `pathlib`, `shutil`).

> [!IMPORTANT]
># The C Version (Hard Mode)
>Side Note: I also wrote a version of this utility entirely in C. Just to see how much more complex it would be.
>
>Compiling and Running the C script
>If you want to try the C version, ensure you have a C compiler like gcc or clang installed.
>
>Run the following command in your terminal to compile the source files into a binary executable:
>
># Compile the main file and the utility functions
>gcc -Wall -Wextra -Werror pyclean.c pyclean_utils.c pyclean.h -o pyclean
>
># Execute the binary
>./pyclean (Note: If you plan to use it globally, you can move the compiled binary to your bin folder: sudo mv pyclean /usr/local/bin/)
