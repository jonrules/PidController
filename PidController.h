#ifndef PidController_h
#define PidController_h

template <class T> class PidController
{
	public:
		const unsigned char TERM_PROPORTIONAL = 1;
		const unsigned char TERM_INTEGRAL = 2;
		const unsigned char TERM_DERIVATIVE = 4;

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

		void addValue(T value);

		T calculate();
		T calculateProportional();
		T calculateIntegral();
		T calculateDerivative();

	private:
		T _targetValue;
		T *_values;
		unsigned char _length;
		unsigned char _terms;

		unsigned int _initialTime;

		float _proportionalGain = 1.0;
		float _integralGain = 1.0;
		float _derivativeGain = 1.0;

}

#endif
