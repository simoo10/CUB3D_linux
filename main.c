#include"cub3d.h"

void texture_init (t_cub *game, t_image *texture, char* path)
{
        game->t[0].img = mlx_xpm_file_to_image(game->mlx, game->no, &(game->t[0].w), &(game->t[0].h));
        if (!game->t[0].img)
        {
            ft_putstr_fd("error: texture '", 2);
            ft_putstr_fd(path, 2);
            ft_putstr_fd("' not found.\n", 2);
            exit (0);
        }
        game->t[0].addr = mlx_get_data_addr(texture->img, &(game->t[0].bits_per_pixel), &(game->t[0].line_length), &(game->t[0].endian));
        game->t[0].x = 0;
        game->t[0].y = 0;
        game->t[1].img = mlx_xpm_file_to_image(game->mlx, game->so, &(game->t[1].w), &(game->t[1].h));
        if (!game->t[1].img)
        {
            ft_putstr_fd("error: texture '", 2);
            ft_putstr_fd(path, 2);
            ft_putstr_fd("' not found.\n", 2);
            exit (0);
        }
        game->t[1].addr = mlx_get_data_addr(texture->img, &(game->t[1].bits_per_pixel), &(game->t[1].line_length), &(game->t[1].endian));
        game->t[1].x = 0;
        game->t[1].y = 0;
        game->t[2].img = mlx_xpm_file_to_image(game->mlx, game->we, &(game->t[2].w), &(game->t[2].h));
        if (!game->t[2].img)
        {
            ft_putstr_fd("error: texture '", 2);
            ft_putstr_fd(path, 2);
            ft_putstr_fd("' not found.\n", 2);
            exit (0);
        }
        game->t[2].addr = mlx_get_data_addr(texture->img, &(game->t[2].bits_per_pixel), &(game->t[2].line_length), &(game->t[2].endian));
        game->t[2].x = 0;
        game->t[2].y = 0;
        game->t[3].img = mlx_xpm_file_to_image(game->mlx, game->ea, &(game->t[3].w), &(game->t[3].h));
        if (!game->t[3].img)
        {
            ft_putstr_fd("error: texture '", 2);
            ft_putstr_fd(path, 2);
            ft_putstr_fd("' not found.\n", 2);
            exit (0);
        }
        game->t[3].addr = mlx_get_data_addr(texture->img, &(game->t[3].bits_per_pixel), &(game->t[3].line_length), &(game->t[3].endian));
        game->t[3].x = 0;
        game->t[3].y = 0;
}
double make_it_good(t_cub *game,double orientation, double o_distance)
{
    double distance;
    double angleDifference;
    angleDifference = fabs(game->orientation - orientation);
    if (angleDifference < PI / 2)
        distance = o_distance * cos(angleDifference);
    else
       distance = o_distance * cos(M_PI - angleDifference);
       return distance;
}
void make_wall(t_cub *cub,double orientation)
{
    double distance_Wall;
    double dis;
    distance_Wall= calcul_distance(cub);
    distance_Wall=make_it_good(cub,orientation,distance_Wall);
    cub->hight_Wall=(64*WIDTH)/distance_Wall;
    cub->top=(HEIGHT/2)-(cub->hight_Wall/2);
    cub->bottom=cub->top+cub->hight_Wall;
}
int get_texture_color(t_image *texture, int x, int y)
{
    int pixel_position;
    unsigned int color;

    if (x < 0 || y < 0 || x >= texture->w || y >= texture->h)
        return (0);
    pixel_position = y * texture->line_length + x * (texture->bits_per_pixel / 8);
    color = *(unsigned int *)(texture->addr + pixel_position);
    return (color);
}

void dr_wall(t_cub *cub, int counter)
{
    int color;
    int y;
    double j;
    double l;
    int text_ort=2;

    //text_ort = 0;
    if(cub->orientation >= 0 && cub->orientation < PI / 2)
    {
       // printf("orientation = %f\n",cub->orientation);
        text_ort = 0;
    }
    else if(cub->orientation >= PI / 2 && cub->orientation < PI)
    {
        //printf("orientation = %f\n",cub->orientation);
        text_ort = 1;
    }
    else if(cub->orientation >= PI && cub->orientation < (PI + PI / 2))
    {
        //printf("orientation = %f\n",cub->orientation);
        text_ort = 2;
    }
    else if(cub->orientation >= (PI + PI / 2) && cub->orientation < (PI * 2))
    {
       // printf("orientation = %f\n",cub->orientation);
        text_ort = 3;
    }
   // printf("text_ort = %d\n",text_ort);
    y=0;
   // if (game->wall[i].side == VERTICAL)
    cub->t[text_ort].x = (int)cub->x_wall % (int)cub->t[text_ort].w;
    cub->t[text_ort].y = 0;
  //  else if (game->wall[i].side == HORIZONTAL)
  //      game->textures[t].x = (int)game->wall[i].y % (int)game->textures[t].w;
    j = (double)cub->t[text_ort].h / cub->hight_Wall;
    while(y<HEIGHT)
    {
        if(y<cub->top)
            color=0xffffff;
        else if(y>cub->bottom)
            color=0x00ff00;
        else
        {
            l = cub->t[text_ort].y;
            if (cub->hight_Wall > HEIGHT)
                 cub->t[text_ort].y += j * (cub->hight_Wall - HEIGHT) / 2;
            color = get_texture_color(&cub->t[text_ort], cub->t[text_ort].x, cub->t[text_ort].y);
            cub->t[text_ort].y = l;
            cub->t[text_ort].y += j;
        }
        my_mlx_pixel_put(cub,counter,y,color);
            y++;
    }
}
void rays(t_cub *pos)
{
    double x;
    double y;
    double num_ray;
    int counter;
    double orientation;
    double or;
    double increment;

   
    num_ray=0;
    counter = 0;
    orientation = pos->orientation - (PI/6);
    increment = (PI/3) / WIDTH;
      while(orientation < pos-> orientation+(PI/6))
    {     
        x = pos->player.x;
        y = pos->player.y;
        //ssssprintf("ori == %d\n" , pos->orientation);
        //or=(PI / 2) / 7;
    while(1)
    {
       
        //orientation = pos->orientation;
        //my_mlx_pixel_put(pos, x, y, 0x1DF235);
        x += cos(orientation);
        y += sin(orientation);
        //printf("-------> x,%d\n",(int)y / SIZE );
         if(y / SIZE <= 0 || x /SIZE <= 0 ||y/SIZE >=pos->map_height ||x / SIZE >= ft_strlen(pos->map[(int)(y / SIZE)]) || pos->map[(int)(y / SIZE)][(int)(x / SIZE)] == '1')
             break;
    }
      pos->x_wall=x;
      pos->y_wall=y; 
      make_wall(pos,orientation);
      
      dr_wall(pos, counter);
      counter++;
        orientation=orientation + increment;
      }
}

double calcul_distance(t_cub *cub)
{
    double distance;
    distance = sqrt(((cub->player.x - cub->x_wall)*(cub->player.x - cub->x_wall) )             +   ((cub->player.y - cub->y_wall)*(cub->player.y - cub->y_wall) ));
    return distance;
}


void init_data(t_data *data)
{
    data->img = NULL;
    data->addr = NULL;
    data->bits_per_pixel = 0;
    data->line_length = 0;
    data->endian = 0;
}
int rendring_minimap(t_cub *cub)
{
    double k;
    mlx_clear_window(cub->mlx, cub->window);
    //draw_map(cub);
    draw_player_position(cub,cub->player.x,cub->player.y);
    rays(cub);
    //k=calcul_distance(cub);

    //printf("------->%f\n",k);
    mlx_put_image_to_window(cub->mlx, cub->window, cub->img, 0, 0);
    return(0);
}

void init_pl(t_player *pl)
{
    pl->x = 0;
    pl->y = 0;
}

void init_cub(t_cub *cub)
{
    cub->map = NULL;
    cub->c=NULL;
    cub->f=NULL;
    cub->ea=NULL;
    cub->we=NULL;
    cub->so=NULL;
    cub->no=NULL;
    cub->count=0;
    cub->mlx=NULL;
    cub->window=NULL;
    cub->height=0;
    cub->width=0;
    cub->x=0;
    cub->y=0;
    cub->pos_x=0;
    cub->pos_y=0;
    cub->img = NULL;
    cub->f_rgb=0;
    cub->c_rgb=0;
    cub->addr = NULL;
    cub->bits_per_pixel = 0;
    cub->line_length = 0;
    cub->endian = 0;
    cub->orientation = 0;
}

void calculateNewPosition(t_cub *cub, float ort, float dist)
{
    float x_new;
    float y_new;

    x_new = cub->player.x + dist * cos(ort);
    y_new = cub->player.y + dist * sin(ort);

    if(cub->map[(int)(y_new/SIZE)][(int)(x_new/SIZE)] == '0')
    {
        cub->player.x = x_new;
        cub->player.y = y_new;
    }
}

int move(int keycode,t_cub *cub)
{
    // printf("=========\n");
    //printf("---%c---keycode = %d--- x=%f--y=%f-\n",cub->map[(int)(cub->player.y)/SIZE][(int)(cub->player.x)/SIZE],keycode,cub->player.x ,cub->player.y );
    if(keycode == 65307)
        exit(0);
    if(keycode == 65361)
    {
        cub->orientation -= (PI / 180) * 2;
        // printf("orientation = %f\n",cub->orientation);
    // calculateNewPosition(&cub->player.x,&cub->player.y,cub->orientation,1);
    }
    if(keycode == 65363)
    {
        cub->orientation += (PI / 180) * 2;
        // printf("orientation = %f\n",cub->orientation);
    //    calculateNewPosition(&cub->player.x,&cub->player.y,cub->orientation,1);
    }
    if(keycode == 119)
    {
        calculateNewPosition(cub,cub->orientation,4);
    }
    if(keycode == 115)
    {
        calculateNewPosition(cub,cub->orientation,-4);
    }
    if(keycode == 97 )
    {
        calculateNewPosition(cub,cub->orientation + (PI*0,5),4);
    }
    if(keycode == 100 )
    {
        calculateNewPosition(cub,cub->orientation -(PI*0,5),4);
    }
    return(0);
}

void fill_orientation(char c,t_cub *cub)
{
    if(c=='N')
        cub->orientation = PI * 1.5;
    if(c=='S')
        cub->orientation = PI * 0.5;
    if(c=='W')
        cub->orientation = 0;
    if(c=='E')
        cub->orientation = PI;
}

void init_player(t_cub *cub)
{
    int i = 0;
    int j = 0;

    while(cub->map[i])
    {
        j = 0;
        while(cub->map[i][j])
        {
            if(cub->map[i][j]=='N' || cub->map[i][j]=='S' || cub->map[i][j]=='W' || cub->map[i][j]=='E')
            {
                cub->player.x = (j * SIZE) + (SIZE / 2);
                // printf("x = %f\n",cub->player.x);
                cub->player.y = (i * SIZE)  + (SIZE / 2);
                cub->map[(int)(cub->player.y)/SIZE][(int)(cub->player.x)/SIZE] = '0';
                // printf("y = %f\n",cub->player.y);
                fill_orientation(cub->map[i][j],cub);
                return;
            }
            j++;
        }
        i++;
    }
}

int main(int c,char **v)
{
    t_cub cub;
    t_player player;
    t_data data;
    int i;
    
    init_data(&data);
    init_cub(&cub);
    init_pl(&player);
    cub.player = player;
    arg_check(v[1],c);
    cub.map = read_map(v[1],&cub);
    i = 0;
    while(cub.map[i])
        i++;
    cub.map_height = i;
    i =0;
   //check_textures_path(&cub);
    map_checking(cub.map);
    // int i = 0;
    // while(cub.map[i])
    // {
    //     // printf("%s\n",cub.map[i]);
    //     i++;
    // }
    check_RGB(cub.c,&cub);
    check_RGB(cub.f, &cub);
    //printf("f = %d\n",cub.f_rgb);
    
    cub.mlx = mlx_init();
    cub.window = mlx_new_window(cub.mlx, WIDTH, HEIGHT, "CUb3D");
    
    texture_init(&cub, &cub.t[0], "./textures/wood0.xpm");
    cub.img = mlx_new_image(cub.mlx, WIDTH, HEIGHT);
    cub.addr = mlx_get_data_addr(cub.img, &cub.bits_per_pixel, &cub.line_length,
                                 &cub.endian);
    // printf("--------\n");
    init_player(&cub);
    // draw_map(&cub);
    mlx_hook(cub.window, 17, 0, (void *)exit, &cub);
    mlx_hook(cub.window, 2, 1L << 0, &move, &cub);
    mlx_loop_hook(cub.mlx, rendring_minimap, &cub);
    mlx_loop(cub.mlx);
}
