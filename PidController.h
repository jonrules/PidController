#ifndef PidController_h
#define PidController_h

template <class T> 
class PidController
{
	public:
		static const unsigned char TERM_PROPORTIONAL = 1;
		static const unsigned char TERM_INTEGRAL = 2;
		static const unsigned char TERM_DERIVATIVE = 4;

		PidController(T targetValue, unsigned char length, unsigned char terms = 0xff);
		~PidController(void);

		unsigned char getTerms();
		void setTerms(unsigned char terms);
		
		float getProportionalGain(void);
		void setProportionalGain(float proportionalGain);
		float getIntegralGain(void);
		void setIntegralGain(float integralGain);
		float getDerivativeGain(void);
		void setDerivativeGain(float derivativeGain);

		T *getValues();

		unsigned long *getTimeValues();

		void addValue(T value);

		T calculate();

	private:
		T _targetValue;
		T *_values;
		unsigned long *_timeValues;
		unsigned char _currentIndex;
		unsigned char _length;
		unsigned char _terms;

		float _proportionalGain = 1.0;
		float _integralGain = 1.0;
		float _derivativeGain = 1.0;

};

#endif
