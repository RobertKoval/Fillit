/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:22:50 by rkoval            #+#    #+#             */
/*   Updated: 2018/01/22 19:57:05 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define BUF_SIZE 550

size_t	ft_validfile(const char *str);
size_t	ft_tetcount(const char *str);
size_t	*ft_collect_size(const char *str, size_t t_count);
size_t	ft_mapsize(size_t f);
char	***ft_makebox(size_t t_count, const size_t *coll);
void	ft_cleanbox(char ***box, const size_t *coll);
void	ft_fillthebox(const char *str, char ***box, const size_t *coll, \
size_t t_count);
char	**ft_initmap(size_t size);
void	ft_cleanmap(char **map);
void 	ft_fillit(const char *str, size_t t_count);
void	*ft_memalloc(size_t size);
void	ft_putendl(const char *s);
void	ft_putstr(const char *s);

#endif
