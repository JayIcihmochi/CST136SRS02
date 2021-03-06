#include "stdafx.h"
#include "canoe.h"
#include "multihull.h"
#include "raft.h"
#include "paddle.h"
#include "sail.h"
#include "sailboat.h"

void Travel(Boat* boat);

int main()
{
	MonoHull straightPoint;
	MultiHull seaStrenght ;
	Paddle seaWackers;
	Sail smoothSailing;

	Raft raft{ "Innominat", &straightPoint };
	Canoe canoe{ "Amonech", &straightPoint };
	Sailboat sailboat{ "Hyanoa", &seaStrenght};

	Boat* boat1{ &raft };

	Travel(boat1);

	Boat* boat2{ &canoe };

	boat2->addPropulsion(&seaWackers);

	Travel(boat2);

	Boat* boat3{ &sailboat };

	boat3->addPropulsion(&smoothSailing);

	Travel(boat3);


    return 0;
}

void Travel(Boat* boat)
{
	if (boat != nullptr)
	{
		while (boat->whatAmIOn() == environment::properties::kwater && !boat->getcaptsized_())
		{
			boat->move();
		}

		if(boat->getcaptsized_())
		{
			//you're dead in the water
		}
		else if (boat->whatAmIOn() == environment::properties::kland)
		{
			//you've beached
		}
		else if (boat->whatAmIOn() == environment::properties::kunknown)
		{
			//you've drifted too far out to sea
		}
	}
}