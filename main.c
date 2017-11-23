#include "libft.h"

#include <fcntl.h> //remove after

#define BUFF_SIZE 4096


int		main(int argc, char **argv) //read file
{
	char ***3dArr = {
	{
		{'.','.','.','#'},
		{'.','.','.','#'},
		{'.','.','.','#'},
		{'.','.','.','#'}
	},
	{
		{'.','.','.','.'},
		{'.','.','.','.'},
		{'.','.','.','.'},
		{'#','#','#','#'}
	},
	{
		{'.','#','#','#'},
		{'.','.','.','#'},
		{'.','.','.','.'},
		{'.','.','.','.'}
	},
	{
		{'.','.','.','.'},
		{'.','.','#','#'},
		{'.','#','#','.'},
		{'.','.','.','.'}
	}
}
				//.<-end->		   <-end->		   <-end->		   <-end->
char **2dArr = {.  // ^ 			  ^				  ^				  ^
		{'.','.','.','#','.','.','.','#','.','.','.','#','.','.','.','#'},  // left-right +/-3 
		{'.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#'},  // up-down +/- 3 
		{'.','#','#','#','.','.','.','#','.','.','.','.','.','.','.','.'},	// l-r +/- 1 , up-down +/- 2
		{'.','.','.','.','.','.','#','#','.','#','#','.','.','.','.','.'}	// l-r +/- 1, u-d +/- <=2
}																					
																
																	//p.s по висота не фіксована!!! 
																	// треба дивитися висоту елемента відносно
																	// всієї висоти


	char buf[BUFF_SIZE + 1];
	(void)argc;
	int fd;
	int red;
	fd = open(argv[1], O_RDONLY);
	red = read(fd, buf, BUFF_SIZE);
	buf[BUFF_SIZE] = '\0';

	//ft_putstr(buf);
	ft_putchar('\n');

	/////
	char **arrai;

	arrai = ft_strsplit(buf, ' ');
	ft_putstr(arrai[0]);
	return (0);
}

///3д масив 



// The goal of this project is to arrange every Tetriminos with each others in order to make
// the smallest possible square. But in some cases, this square should contains holes when
// some given pieces won’t fit in perfectly with others.
// Even if they are embedded in a 4x4 square, each Tetrimino is defined by its minimal
// boundaries (their ’#’). The 12 remaining empty characters will be ignored for the
// Tetriminos assemble process.
// Tetriminos are ordered by they apparition order in the file. Among all the possible
// candidates for the smallest square, we only accept the one where Tetriminos is placed on
// their most upper-left position.






