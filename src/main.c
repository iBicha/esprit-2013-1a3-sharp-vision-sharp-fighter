/*TODO :
    -Conserving Textures when recreating GL context (change resolution)

*/
#include "includes.h"


int main()
{
    int i,w=1366/2, h=768/2, fullscreen=0, depth=32;
int intro ;
int state=1,choix=0;
    GFX_MODE_LIST * gfxlist;
int control[]={KEY_UP,KEY_DOWN,KEY_RIGHT,KEY_LEFT,KEY_A,KEY_Z,KEY_E};


        //intialization
    if(install(fullscreen,w,h,depth))
        return 1;//ERROR


    //Get possible resolutions
    gfxlist=get_gfx_mode_list(GFX_OPENGL_FULLSCREEN);
    printf("\nGraphics modes : %d\n",gfxlist->num_modes);
    for(i=0; i<gfxlist->num_modes; i++)
    {
        printf("%dx%dx%d\n",gfxlist->mode[i].width,gfxlist->mode[i].height,gfxlist->mode[i].bpp);
    }

intro=AddVoice("Resources/Sounds/intro.wav");
PlayVideo("Resources/Videos/SharpIntro.ogv");
voice_start(intro);
 voice_set_playmode(intro, PLAYMODE_LOOP);
while (state)
{
   mainmenu(&choix);

    switch (choix)
    {
        case 0 :
    break;
    case 1:
    versus();
    break;
    case 2 :
    setting (intro,gfxlist,fullscreen);
    break;
        case 3 :{
     voice_stop(intro);
         credit();
         voice_start(intro);

         }
         break;
         case 4 :
         state=0;
         break;
    }

}

     voice_stop(intro);
    uninstall();//liberation de memoire
    return 0;
}
END_OF_MAIN()
