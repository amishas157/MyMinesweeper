#include <gtk/gtk.h>
#include<gtk/gtkwidget.h>
 GtkWidget *cell[9][9];
  GtkWidget *flag[9][9];
  GtkWidget *sum[9][9];
  GtkWidget *mine[9][9];
  GtkWidget *window;
struct box
{
	int mine;
	int mine_sum;
}arr[9][9],arr2[9][9];

void show_all_mine()
{
int i,j;
 for(i=0;i<9;i++)
   {
     for(j=0;j<9;j++)
      {
        if(arr[i][j].mine==1)
          {
 
            gtk_widget_hide (cell[i][j]);
            gtk_widget_hide (flag[i][j]);
            gtk_widget_hide(sum[i][j]);
            gtk_widget_show(mine[i][j]);
           }
       }
    }
 	gtk_widget_set_sensitive(window, FALSE);
}
typedef struct _identifier{
    int x;
    int y;
}identifier;


void reveal(int r,int s)
{
	if(arr[r][s].mine_sum!=0)
	{
         gtk_widget_hide (cell[r][s]);
         gtk_widget_hide (flag[r][s]);
         gtk_widget_hide(sum[r][s]);
         gtk_widget_hide(mine[r][s]);
         gtk_widget_show(sum[r][s]);
	 arr2[r][s].mine_sum=arr[r][s].mine_sum;
        }
	else
	{
            gtk_widget_hide (cell[r][s]);
            gtk_widget_hide (flag[r][s]);
            gtk_widget_hide(sum[r][s]);
            gtk_widget_hide(mine[r][s]);
            gtk_widget_show(sum[r][s]);
		arr2[r][s].mine_sum=0;
		if(r!=0&&s!=0)
		{
		if(arr2[r-1][s-1].mine_sum==-1)
		reveal(r-1,s-1);
	        }
		if(r!=0)
		{
			
		if(arr2[r-1][s].mine_sum==-1);
		reveal(r-1,s);
	        }
		if(r!=0&&s!=8)
		{if(arr2[r-1][s+1].mine_sum==-1)
		reveal(r-1,s+1);
	        }
		if(s!=0)
		{if(arr2[r][s-1].mine_sum==-1)
		reveal(r,s-1);
	        }
		if(s!=8)
		{
		if(arr2[r][s+1].mine_sum==-1)
		reveal(r,s+1);
	        }
		if(r!=8&&s!=0)
		{if(arr2[r+1][s-1].mine_sum==-1)
		reveal(r+1,s-1);
	        }
	  	if(r!=8)
		{if(arr2[r+1][s].mine_sum==-1)
		reveal(r+1,s);
	        }
		if(r!=8&&s!=8)
		{if(arr2[r+1][s+1].mine_sum==-1)
		reveal(r+1,s+1);
	        }
	}
	
}

static gboolean button_press_event( GtkWidget *widget, GdkEventButton *event, gpointer data)
{
   identifier *id = data;

  if (event->button == 1)
  {
 gtk_widget_hide (widget);
 gtk_widget_hide (flag[id->x][id->y]);
 gtk_widget_hide(sum[id->x][id->y]);
 gtk_widget_hide(mine[id->x][id->y]);
 if(arr[id->x][id->y].mine==1)
 {
  show_all_mine();
 }
 else
   {
  reveal(id->x,id->y); 
    }
 
  }
 else 
 {
   gtk_widget_hide (widget);
   gtk_widget_show(flag[id->x][id->y]);

   }

  return TRUE;
}

int main( int argc, char *argv[])
{

int i,j,p;
 int mine_count=10;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
		arr[i][j].mine=0;
		arr[i][j].mine_sum=0;
		arr2[i][j].mine_sum=-1;
	    }
	}
	int r,s;
	srand(time(NULL));
	for(p=0;p<10;p++)
	{
		do
		{
		r=rand()%9;
		s=rand()%9;
	        }
	    while(arr[r][s].mine!=0);
		arr[r][s].mine=1;
	}

for(i=1;i<8;i++)
	{
		for(j=1;j<8;j++)
		{
arr[i][j].mine_sum=(arr[i-1][j-1].mine+arr[i-1][j].mine+arr[i-1][j+1].mine+arr[i][j-1].mine+arr[i][j+1].mine+arr[i+1][j-1].mine+arr[i+1][j].mine+arr[i+1][j+1].mine);
		}
	}
	for(i=1;i<8;i++)
	{
		int j=0;
		arr[i][j].mine_sum=arr[i-1][j].mine+arr[i-1][j+1].mine+arr[i][j+1].mine+arr[i+1][j].mine+arr[i+1][j+1].mine;
	}
	for(i=1;i<8;i++)
	{
	   int j=8;
		arr[i][j].mine_sum=arr[i-1][j].mine+arr[i-1][j-1].mine+arr[i][j-1].mine+arr[i+1][j].mine+arr[i+1][j-1].mine;
	}
	for(j=1;j<8;j++)
	{
		int i=0;
		arr[i][j].mine_sum=arr[i][j-1].mine+arr[i][j+1].mine+arr[i+1][j-1].mine+arr[i+1][j].mine+arr[i+1][j+1].mine;
	}
	for(j=1;j<8;j++)
	{
		int i=8;
		arr[i][j].mine_sum=arr[i][j-1].mine+arr[i][j+1].mine+arr[i-1][j-1].mine+arr[i-1][j].mine+arr[i-1][j+1].mine;
	}
	{
		arr[0][0].mine_sum=arr[0][1].mine+arr[1][0].mine+arr[1][1].mine;
		arr[0][8].mine_sum=arr[0][7].mine+arr[1][7].mine+arr[1][8].mine;
		arr[8][0].mine_sum=arr[7][0].mine+arr[7][1].mine+arr[8][1].mine;
		arr[8][8].mine_sum=arr[8][7].mine+arr[7][7].mine+arr[7][8].mine;
	}
	
















  

  GtkWidget *table;
  
  GtkWidget *label;
  GdkColor color,color1;
  gdk_color_parse( "black", &color );
  gdk_color_parse( "white", &color1 );
 
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 250, 180);
  gtk_window_set_title(GTK_WINDOW(window), "My Minesweeper");

  gtk_container_set_border_width(GTK_CONTAINER(window), 5);

  table = gtk_table_new(9, 9, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);

   i = 0;
   j = 0;
identifier id[81]; 
    unsigned int counter = 0;
  int pos = 0;
  for( i=0; i < 9; i++) {
    for( j=0; j < 9; j++) {
      char buf[5];
      
            id[counter].x = i;
            id[counter].y = j;
   sprintf(buf, "%d", arr[i][j].mine_sum);
      cell[i][j]= gtk_button_new_with_label(" ");
      flag[i][j] = gtk_image_new_from_file("flag.png");
      mine[i][j] = gtk_image_new_from_file("mine.png");
      sum[i][j] = gtk_label_new(NULL);
      gtk_label_set_text(GTK_LABEL(sum[i][j]),buf);
      gtk_widget_set_size_request(flag[i][j], 40, 40);
      gtk_table_attach_defaults(GTK_TABLE(table), cell[i][j], j, j+1, i, i+1 ); 
      gtk_table_attach_defaults(GTK_TABLE(table), flag[i][j], j, j+1, i, i+1 );
      gtk_table_attach_defaults(GTK_TABLE(table), mine[i][j], j, j+1, i, i+1 );
      gtk_table_attach_defaults(GTK_TABLE(table), sum[i][j], j, j+1, i, i+1 );
      gtk_widget_modify_bg( GTK_WIDGET(cell[i][j]), GTK_STATE_NORMAL, &color );
      gtk_widget_modify_fg( GTK_WIDGET(sum[i][j]), GTK_STATE_NORMAL, &color );
      gtk_signal_connect(GTK_OBJECT(cell[i][j]), "button_press_event",(GtkSignalFunc) button_press_event, &id[counter]);
     
      counter++;
      pos++;
    }
  } 

  gtk_container_add(GTK_CONTAINER(window), table);

  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
