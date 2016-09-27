//
// Created by discord on 26/09/16.
//

#ifndef MOTORDAEMON_ODOMETRY_HPP
#define MOTORDAEMON_ODOMETRY_HPP


#include <cstdint>
#include <glib.h>

class Odometry {


private:

    static long leftTicks;
    static long rightTicks;
    static uint8_t firstChanL;
    static uint8_t firstChanR;

    static gboolean onTickChanALeft(GIOChannel *channel,
                                    GIOCondition condition,
                                    gpointer user_data);
    static gboolean onTickChanBLeft(GIOChannel *channel,
                                    GIOCondition condition,
                                    gpointer user_data);
    static gboolean onTickChanARight(GIOChannel *channel,
                                    GIOCondition condition,
                                    gpointer user_data);
    static gboolean onTickChanBRight(GIOChannel *channel,
                                    GIOCondition condition,
                                    gpointer user_data);

public:
    Odometry(uint8_t chanAL, uint8_t chanBL, uint8_t chanAR, uint8_t chanBR);
    long getLeftValue();
    long getRightValue();
};

long Odometry::leftTicks;
long Odometry::rightTicks;
uint8_t Odometry::firstChanL; //1 : chanA ; 2 : chanB
uint8_t Odometry::firstChanR; //1 : chanA ; 2 : chanB


#endif //MOTORDAEMON_ODOMETRY_HPP
