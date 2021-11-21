#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class DMA{
	private:
		char* label;
		int rating;
	public:
		DMA(const char * l = "null", int r = 0);
		DMA(const DMA& rs);
		DMA& operator=(const DMA& rs);
		virtual void View() const = 0;
		friend std::ostream& operator<<(std::ostream& os, const DMA& rs);
		virtual ~DMA();

};


// Default copy constructor calling copy constructors 
// of all copy constructors
// base clases

class baseDMA : public DMA
{
	public:
		// Нужен ли здесь конструктор копирования?
		baseDMA(const char* l = "null", int r = 0);
		~baseDMA();
		void View() const;
		// Проверить есть ли доступ у дружественной функции к полями родителя (DMA)
		// будет ли дружественная функция иметь доступ к label и rating? - нет
		friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

class lacksDMA: public DMA
{
	private:
		enum { COL_LEN = 40 };
		char color[COL_LEN];
	public:
		// А здесь нужен ли конструктор копирования? - нет
		// автоматически сгенирированный конструктор копирования
		// вначале вызовет конструктор базового класса (DMA) со ссылкой
		// на дочерний (lacksDMA) - так можно и это конструктор определен.
		// И затем скопирует массив (являющийся автоматическим) в часть относящийся
		// к lacksDMA
		void View() const;
		lacksDMA(const char* l = "null", const char* c = "no color", int r = 0);
		lacksDMA(const char* c, const DMA& rs);
		~lacksDMA();
		friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};

class hasDMA : public DMA
{
	private:
		char * style;
	public:
		hasDMA(const char* s = "none", const char * l = "null", int r = 0);
		hasDMA(const char* s, const DMA& rs);
		hasDMA(const hasDMA& hs);
		~hasDMA();
		void View() const;
		hasDMA& operator=(const hasDMA& rs);
		friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};


#endif
