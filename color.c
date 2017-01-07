/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 01:21:16 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/07 10:54:36 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			color_scale_brg(int i)
{
	if (i < 0)
		i = -i;
	while (i >= 768)
		i -= 768;
	if (i < 256)
		return (0x0000FF + (i * 0x010000) - i);
	else if (i < 512)
		return (0xFF0000 - ((i - 256) * 0x010000) + ((i - 256) * 0x000100));
	else
		return (0x00FF00 - ((i - 512) * 0x000100) + (i - 512));
}

int			color_scale_rby(int i)
{
	if (i < 0)
		i = -i;
	while (i >= 768)
		i -= 768;
	if (i < 256)
		return (0xFF00FF - (i * 0x010000) + (i * 0x000100));
	else if (i < 512)
		return (0x00FFFF + ((i - 256) * 0x010000) - (i - 256));
	else
		return (0xFFFF00 - ((i - 512) * 0x000100) + (i - 512));
}

int			color_scale_ry(int i)
{
	if (i < 0)
		i = -i;
	while (i >= 512)
		i -= 512;
	if (i < 256)
		return (0xFF0000 + (i * 0x000100));
	else
		return (0xFFFF00 - ((i - 256) * 0x000100));
}

int			color_scale_perso(int i)
{
	if (i < 0)
		i = -i;
	while (i >= 1536)
		i -= 1536;
	if (i < 256)
		return (0x0000FF + (i * 0x010000) - i);
	else if (i < 512)
		return (0xFF0000 + ((i - 256) * 0x000100));
	else if (i < 768)
		return (0xFFFF00 - ((i - 512) * 0x010000));
	else if (i < 1024)
		return (0x00FF00 + ((i - 768) * 0x010000) + (i - 768));
	else if (i < 1280)
		return (0xFFFFFF - ((i - 1024) * 0x010000));
	else
		return (0x00FFFF - ((i - 1280) * 0x000100));
}

int			color_scale(int i, int pattern)
{
	if (pattern < 0)
		pattern = -pattern;
	while (pattern > 3)
		pattern -= 4;
	if (pattern == 0)
		return (color_scale_brg(i));
	else if (pattern == 1)
		return (color_scale_rby(i));
	else if (pattern == 2)
		return (color_scale_ry(i));
	else
		return (color_scale_perso(i));
}
