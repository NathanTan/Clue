/*room.h*/

#pragma once

///////////////////////////////////////////////
//NOTE: this game is built with the assumption
//that the player will only travel to the rooms
//listed as adjacent/cornered/secret pass 
////////////////////////////////////////////////
struct rstat{
   string name;
   int distance; //minimum dice role required to enter the room
};


struct ac{
   struct rstat adjacent1;
struct rstat adjacent2;
   struct rstat secret_passage;
   struct rstat corner1;
   struct rstat corner2;
};

struct room{
   string name;
   struct ac access;
};


