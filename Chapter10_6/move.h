#ifndef MOVE_H_
#define MOVE_H_

class Move{
	private:
		double x;
		double y;
	public:
		// Set x and y to a and b
		Move(double a = 0, double b = 0);
		// Show current values of x and y
		void showmove() const;
		// Add x from m to x of caller (*this) for getting new value of x,
		// Add y from m to y of caller (*this) for getting new value of y,
		// assign to initialized object values x and y and return him.
		Move add(const Move& m) const;
		// Reset x and y of this to a nad b
		void reset(double a = 0, double b = 0);
};

#endif
