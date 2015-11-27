#ifndef PidController_h
#define PidController_h

template <class T> 
class PidController
{
	public:
		static const unsigned char TERM_PROPORTIONAL = 1;
		static const unsigned char TERM_INTEGRAL = 2;
		static const unsigned char TERM_DERIVATIVE = 4;

		PidController(T targetValue, unsigned long sampleTime, unsigned char terms = 0xff);
		~PidController(void);

		unsigned char getTerms();
		void setTerms(unsigned char terms);
		
		float getProportionalGain(void);
		void setProportionalGain(float proportionalGain);
		float getIntegralGain(void);
		void setIntegralGain(float integralGain);
		float getDerivativeGain(void);
		void setDerivativeGain(float derivativeGain);

		T getLastError();

		unsigned long getLastTime();

		T calculate(T value);

	private:
		T _targetValue;
		T _lastError;
		T _lastResult;
		unsigned long _lastTime;
		unsigned long _sampleTime;
		unsigned char _currentIndex;
		unsigned char _terms;

		float _proportionalGain = 1.0;
		float _integralGain = 1.0;
		float _derivativeGain = 1.0;

};

#endif
