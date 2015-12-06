#ifndef PidController_h
#define PidController_h

template <class T> 
class PidController
{
	public:
		static const unsigned char TERM_PROPORTIONAL = 1;
		static const unsigned char TERM_INTEGRAL = 2;
		static const unsigned char TERM_DERIVATIVE = 4;
		static const unsigned char TERM_ALL = 7;

		PidController(void);
		PidController(T targetValue);
		PidController(T targetValue, unsigned long sampleTime);
		PidController(T targetValue, unsigned long sampleTime, unsigned char terms);
		PidController(T targetValue, unsigned long sampleTime, unsigned char terms, T tolerance);
		~PidController(void);

		T getTargetValue(void);
		void setTargetValue(T targetValue);

		unsigned long getSampleTime(void);
		void setSampleTime(unsigned long sampleTime);

		unsigned char getTerms(void);
		void setTerms(unsigned char terms);

		T getTolerance(void);
		void setTolerance(T tolerance);
		
		float getProportionalGain(void);
		void setProportionalGain(float proportionalGain);
		float getIntegralGain(void);
		void setIntegralGain(float integralGain);
		float getDerivativeGain(void);
		void setDerivativeGain(float derivativeGain);

		T getLastError(void);
		T getLastResult(void);
		unsigned long getLastTime(void);

		T calculate(T value);

	private:
		T _targetValue;
		T _lastError;
		T _lastResult;
		T _lastIntegralResult;
		T _lastDerivativeResult;
		T _tolerance;
		unsigned long _lastTime;
		unsigned long _sampleTime;
		unsigned char _currentIndex;
		unsigned char _terms;

		float _proportionalGain = 1.0;
		float _integralGain = 1.0;
		float _derivativeGain = 1.0;

};

#endif
