#include "stdafx.h"
#include "canoe.h"
#include "multihull.h"
#include <iostream>
#include "raft.h"
#include "paddle.h"
#include "sail.h"

void Travel(Boat* boat);

int main()
{
	MonoHull straightPoint;
	MultiHull seaStrenght ;
	Paddle seaWackers;
	Sail smoothSailing;

	Raft raft{ "Inomenot", &straightPoint };

	

	Boat* boat1{ &raft };

	Travel(boat1);




    return 0;
}

void Travel(Boat* boat)
{
	if (boat != nullptr)
	{
		while (boat->whatAmIOn() == environment::properties::kwater)
		{
			boat->move();
		}
	}
}