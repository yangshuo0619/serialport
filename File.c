#include <stdio.h>
#include "File.h"
#include <string.h>

/***************************************************************
* creat robot sensor bash file 
***************************************************************/
int create_robot_info(char *path, struct RobotInfo *robot_info)
{

    FILE *fp = NULL;
    fp = fopen(path, "w+");
    fprintf(fp, "#!/bin/bash \n");
    fprintf(fp, "export MYNTBOT_BASE=\'%s\'\n", robot_info->base);
    fprintf(fp, "export MYNTBOT_LASER_SENSOR=\'%s\'\n", robot_info->laser);
    fprintf(fp, "export MYNTBOT_3D_SENSOR=\'%s\'\n", robot_info->camera);
    fclose(fp);
    chmod(path, S_IRWXU | S_IRWXG | S_IRWXO );
   
    return 1;
}

/*int main()
{
    strcpy(robot_info.base, "base2");
    strcpy(robot_info.laser, "ls01b");
    strcpy(robot_info.camera, "mynteye_s");
    char *path = "/home/owen/c-test/serialport/tmp/test.bash";
    int flag = create_robot_info(path, &robot_info );
    printf("create robot info %d \n", flag);
    return 0;
}*/
