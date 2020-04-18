# GET NEXT LINE

Get Next Line (or as it's more commonly known getline()) is one of the first projects in the 42 curriculum. The goal of GNL is to parse a file descriptor and return the next full line.

## Getting Started

This project uses a stripped down version of [my 42 library](https://github.com/mint42/libft), which has already been included in this repository for ease of use. To set up this project, run `git clone https://github.com/mint42/gnl` in the folder of your choosing. You can compile the libft library by running the `make -C ./libft` or by running `make` inside the libft folder.

To compile the library and the GNL together, run this command:

```
gcc get_next_line.c EXAMPLE_MAIN.c -I./ -I./libft/includes -L./libft -lft
```

Then run the program using `./a.out`.

## Notes

This completed GNL project is included in, and maintained by [my personal 42 library](https://github.com/mint42/libft). This repository is only here for record of the submitted project.

The test case provided is pretty bare, it just reads and prints the EXAMPLE_MAIN.c file. Feel free to play with the file.

## Authors

[Ari Reedy](https://github.com/mint42/)
