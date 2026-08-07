#!/usr/bin/env python3

from pathlib import Path
import shutil

# colors for text :)
blue = "\033[94m"
red = "\033[91m"
green = "\033[92m"
reset = "\033[0m"


# path obj rglob() method essentially does the same as find . -type d, which searches recursively for the dir and returns "generators objects"
# These functions are iterators, everytime you call it they return the next thing
def ft_clean_print(current_dir) -> None:
    count = 0

    to_del: list[str] = [
        "__pycache__",
        ".mypy_cache",
        ".DS_Store",
        ".vscode"
    ]
    for name in to_del:
        for file in current_dir.rglob(name):
            try:
                if file.is_file():
                    file.unlink() # built in method for the return path obj
                    count += 1
                else:
                    shutil.rmtree(file)  # shutil is a built in module (pre written func)
                    count += 1
                print(f"{green}Removed{reset}: {file}")
            except OSError as e:
                print(f"{red}Couldn't remove {file}: {e}{reset}")

    if count > 0:
        print(f"{green}Sucessfully cleaned {count} files{reset}")
    else:
        print(f"Nothing to clean...")


def ft_pyclean() -> None:
    print(f"====== Welcome to {blue}PYCLEAN{reset} ======\n")
    current_dir = Path(".")
    usr_in: str = input(f"""Are you sure you want to run {blue}PYCLEAN{reset} on this dir?
All __pycache__ / .mypy_cache folders {red}will be deleted{reset} [y/n]: """)
    
    if usr_in.lower() == "y":
        ft_clean_print(current_dir)
    elif usr_in.lower() == "n":
        print(f"\nOK :), {blue}PYCLEAN{reset} will quit...")
    else:
        print(f"\nInvalid input, {blue}PYCLEAN{reset} will quit...")

if __name__ == "__main__":
    ft_pyclean()