#ifndef HUMAN_H
#define HUMAN_H

class Human : public NPC {
	public:
    Human(unsigned int _stamina,unsigned int _fear);
	protected:
    unsigned int stamina, fear;
};

#endif
