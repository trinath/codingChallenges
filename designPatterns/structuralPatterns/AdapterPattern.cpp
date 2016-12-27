/*
Source: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns

Problem:
Convert the interface of a class into another interface that clients expect.
Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.
*/

#include <iostream>

class Muslim {  // Abstract Target
        public:
	        virtual ~Muslim() = default;
	        virtual void performsMuslimRitual() const = 0;
};

class MuslimFemale : public Muslim {  // Concrete Target
        public:
	        virtual void performsMuslimRitual() const override {std::cout << "Muslim girl performs Muslim ritual." << std::endl;}
};

class Hindu {  // Abstract Adaptee
        public:
	        virtual ~Hindu() = default;
	        virtual void performsHinduRitual() const = 0;
};

class HinduFemale : public Hindu {  // Concrete Adaptee
        public:
	        virtual void performsHinduRitual() const override {std::cout << "Hindu girl performs Hindu ritual." << std::endl;}
};

class MuslimRitual {
        public:
	        void carryOutRitual (Muslim* muslim) {
		        std::cout << "On with the Muslim rituals!" << std::endl;
		        muslim->performsMuslimRitual();
	        }
};

class MuslimAdapter : public Muslim {  // Adapter
	private:
		Hindu* hindu;
	public:
		MuslimAdapter (Hindu* h) : hindu(h) {}
		virtual void performsMuslimRitual() const override {hindu->performsHinduRitual();}
};

int main() {  // Client code
	HinduFemale* hinduGirl = new HinduFemale;
	MuslimFemale* muslimGirl = new MuslimFemale;
	MuslimRitual muslimRitual;
	MuslimAdapter* adaptedHindu = new MuslimAdapter (hinduGirl);  

	muslimRitual.carryOutRitual (muslimGirl);
	muslimRitual.carryOutRitual (adaptedHindu);  
	delete adaptedHindu;  
	delete hinduGirl;
	delete muslimGirl; 
	return 0;
}
