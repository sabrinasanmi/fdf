void	render(mlx_image_t *image, t_pt3 **map, t_settings *cfg, mlx_t *mlx)
{
	t_vector2	u;
	t_vector2	v;
	int			x;
	int			y;
	t_pt2		**points;

	(void) mlx;
	memset(image->pixels, 0, image->width * image->height * sizeof(int32_t));
	get_base_vectors(&u, &v, cfg);
	points = make_points(u, v, map, cfg);
	x = 0;
	while (x < cfg->map_height)
	{
		y = 0;
		y = 0;
		y = 0;
		y = 0;
		y = 0;
	}
	x = 0;
	while (x < cfg->map_height)
	{
		free(points[x]);
		x++;
	}
	free(points);
}
