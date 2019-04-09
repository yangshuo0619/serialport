#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
 
struct RobotInfo
{
    char base[20];
    char laser[20];
    char camera[20];
}robot_info;

int creat_robot_info(struct RobotInfo *robot_info);

#endif
