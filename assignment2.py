# Assignment 2
# Refactor code
# -------------
# Not timed (good to get it back within 24 hours)
#
# An intern has provided the code below to update the version number
# within two different files.
# The intern has left and you need to review and improve the code before
# submitting to source control.
#
# Please do not be constrained by the existing code (i.e. you don't have
# to keep the same function names, structure)
# Aim for production quality 'best-practice/clean' code
#
# Original Requirements
# ---------------------
# A script in a build process needs to update the build version number in 2
# locations.
# - The version number will be in an environment variable "BuildNum"
# - The files to be modified will be under "$SourcePath/develop/global/src"
# directory
# - The "SConstruct" file has a line "point=123," (where 123
# (just an example) should be updated with the value of "BuildNum"
# Environment variable)
# - The "VERSION"file has a line "ADLMSDK_VERSION_POINT= 123" (where 123
# (just an example) should be updated with the value of "BuildNum"
# Environment variable)

import os
import re

def update_version_in_file(filepath: str, pattern: str, replacement: str) -> None:
    """
    Updates the specific line in a file based on a regex pattern.
    Args:
        filepath (str): The path to the file to update.
        pattern (str): The regx pattern to find the line to update.
        replacement (str): The replacement string.
    """

    try:
        # Create a temporary file
        temp_filepath = filepath + ".tmp"

        # Change file permission to allow write
        os.chmod(filepath, 0o755)

        with open(filepath, 'r') as fin, open(temp_filepath, 'w') as fout:
            for line in fin:
                updated_line = re.sub(pattern, replacement, line)
                fout.write(updated_line)

        # Replace original file with the temporary file
        os.remove(filepath)
        os.rename(temp_filepath, filepath)
        print(f"Successfully updated version in {filepath} with {replacement}")

    except FileNotFoundError:
        print(f"File not found: {filepath}")
    except OSError as e:
        print(f"OSError occurred: {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")


# SCONSTRUCT file interesting lines
# config.version = Version(
# major=15,
# minor=0,
# point=6,
# patch=0
#)
def update_sconstruct(source_path: str, build_num: str) -> None:
    """
    Updates the build number in the SConstruct file
    Args:
        source_path (str): The root path where the SCONSTRUCT file is located.
        build_num (str): The build number to update.
    """

    filepath = os.path.join(source_path, "develop", "global", "src", "SConstruct")
    pattern = r"point\=[\d]+"
    replacement = f"point={build_num}"
    update_version_in_file(filepath, pattern, replacement)


# VERSION file interesting line
# ADLMSDK_VERSION_POINT=6
def update_version(source_path: str, build_num: str) -> None:
    """
    Updates the build number in the VERSION file
    Args:
        source_path (str): The root path where the VERSION file is located.
        build_num (str): The build number to update.
    """

    filepath = os.path.join(source_path, "develop", "global", "src", "VERSION")
    pattern = r"ADLMSDK_VERSION_POINT=[\d]+"
    replacement = f"ADLMSDK_VERSION_POINT={build_num}"
    update_version_in_file(filepath, pattern, replacement)


def main() -> None:
    """
    Main function to update version numbers in files.
    """

    source_path = os.environ.get("SourcePath")
    build_num = os.environ.get("BuildNum")
    if not source_path or not build_num:
        print("SourcePath or BuildNum environment variables not set.")
        return

    update_sconstruct(source_path, build_num)
    update_version(source_path, build_num)


if __name__ == "__main__":
    main()

# Before executing this script, set the SourcePath and BuildNum environment variables first.
# Example:
# export SourcePath="/workspaces/ApplicantzSoftwareDeveloperTest/assignment2_test"
# export BuildNum="999"
# python assignment2.py