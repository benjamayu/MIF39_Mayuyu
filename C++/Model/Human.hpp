#ifndef HUMAN_H
#define HUMAN_H

class Human : public NPC {
	public:
	Human(unsigned int _fatigue,unsigned int _peur);
	protected:
	unsigned int fatigue,peur;
};

#endif
