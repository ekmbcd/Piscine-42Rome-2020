/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:00:27 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/08 18:00:33 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_prints(char *str);
int		ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find);
int		ft_checkunits(char *str, char *to_search);
int		ft_checkteens(char *str, char to_search[2]);
int		ft_checktens(char *str, char to_search[2]);
int		ft_check100(char *str);
int		ft_handleten(char *num, char *line);
int		ft_insidesearch(char *num, int len, char *line);
int		ft_search(char *num, int len, char *dict);
void	ft_units(char *num, char *dict);
void	ft_tens(char num[2], char *dict);
void	ft_hundreds(char num[3], char *dict);
char	*ft_cut_string(char *str);
void	ft_zeroes(char *num, char *dict);
void	ft_rec(char *str, char *dict);
char	*ft_open_dict(char *filename);
int		ft_error(void);
int		ft_checkinput(char *num);
void	ft_prints_from_file(void);
void	ft_start_program(char *num, char *dict);
void	ft_set_error(void);

#endif
