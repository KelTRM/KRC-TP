# Table of contents

* [Command line](#command-line)
* [Command line](#input-files)
* [Command line](#output-files)

# Command line

The command line arguments for KRC-TP are made up like this:

`krc-tp -flag flag argument`

Very simple and common format.

## Input file(s)

The input files are considered to be anything which does not come after a flag.

Example: `krc-tp input_file.rlc -flag not_an_input_file another_input_file.rlc`

## Output file(s)

Output files are specified with the `-o` flag.

Example: `krc-tp input_file.rlc -o output_file.h`

# Flags

* `-o`: Specifies an output file ([Info here](#output-files))