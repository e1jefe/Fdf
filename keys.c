//
// Created by Dmytro SHEPTUN on 2/26/18.
//
#include "fdf.h"

//static int     ft_keys(int key, void *zlx)
//{
//	t_mapinfo *mlx;
//
//	printf("key = %d\n", key);
//	mlx = (t_mapinfo*)zlx;
//	if (key == 53)
//		exit(0);
//	return (0);
//
//}

//static void	key_rot(int keycode, t_mapinfo *map)
//{
//	if (keycode == 12)
//		map->rot_y += ANGL;
//	if (keycode == 14)
//		map->rot_y -= ANGL;
//	if (keycode == 13)
//		map->rot_x += ANGL;
//	if (keycode == 1)
//		map->rot_x -= ANGL;
//	if (keycode == 0)
//		map->rot_z += ANGL;
//	if (keycode == 2)
//		map->rot_z -= ANGL;
//}
//
//static void	key_scale(int keycode, t_mapinfo *map)
//{
//	if (keycode == 123)
//		map->scale_x -= 1;
//	if (keycode == 124)
//		map->scale_x += 1;
//	if (keycode == 126)
//		map->scale_y += 1;
//	if (keycode == 125)
//		map->scale_y -= 1;
//}
//
//static void	key_reset(t_mapinfo *map)
//{
//	map->rot_y = 110;
//	map->rot_z = -125;
//	map->rot_x = 245;
//	map->scale_x = map->ori_x;
//	map->scale_y = map->ori_y;
//}
//
//int			key_hook(int keycode, t_mapinfo *map)
//{
//	t_mapinfo mapcpy;
//
//	mapcpy = *map;
//	mapcpy.points = ft_mapcopy(map);
//	if (keycode == 53)
//		exit(0);
//	else if (keycode == 15)
//		key_reset(map);
//	else if (keycode >= 0 && keycode <= 14)
//		key_rot(keycode, map);
//	else if (keycode >= 123 && keycode <= 126)
//		key_scale(keycode, map);
//	mlx_clear_window(0, map->win);
//	scale_points(&mapcpy, mapcpy.scale_x, mapcpy.scale_y);
//	rotate_x(map->rot_x, &mapcpy);
//	rotate_y(map->rot_y, &mapcpy);
//	rotate_z(map->rot_z, &mapcpy);
//	ft_centremap(&mapcpy);
//	ft_draw_map(mapcpy);
//	free_map(mapcpy);
//	ft_putnbr(keycode);
//	ft_putchar('\n');
//	return (0);
//}