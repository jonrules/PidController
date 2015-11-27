#include <PidController.h>
#include <Arduino.h>
#include <math.h>

template <class T>
PidController<T>::PidController(void)
{
	PidController(0, 100, TERM_ALL, (T)0);
};

template <class T>
PidController<T>::PidController(T targetValue)
{
	PidController(targetValue, 100, TERM_ALL, (T)0);
};

template <class T>
PidController<T>::PidController(T targetValue, unsigned long sampleTime)
{
	PidController(targetValue, sampleTime, TERM_ALL, (T)0);
};

template <class T>
PidController<T>::PidController(T targetValue, unsigned long sampleTime, unsigned char terms)
{
	PidController(targetValue, sampleTime, terms, (T)0);
};

template <class T>
PidController<T>::PidController(T targetValue, unsigned long sampleTime, unsigned char terms, T tolerance)
{
	_targetValue = targetValue;
	_sampleTime = sampleTime;
	_terms = terms;
	_lastTime = millis();
	_tolerance = tolerance;
};

template <class T>
PidController<T>::~PidController(void)
{
	
};

template <class T>
T PidController<T>::getTargetValue(void)
{
	return _targetValue;
};

template <class T>
void PidController<T>::setTargetValue(T targetValue)
{
	_targetValue = targetValue;
};

template <class T>
unsigned long PidController<T>::getSampleTime(void)
{
	return _sampleTime;
};

template <class T>
void PidController<T>::setSampleTime(unsigned long sampleTime)
{
	_sampleTime = sampleTime;
};

template <class T>
unsigned char PidController<T>::getTerms(void)
{
	return _terms;
};

template <class T>
void PidController<T>::setTerms(unsigned char terms)
{
	_terms = terms;
};

template <class T>
T PidController<T>::getTolerance(void)
{
	return _tolerance;
};

template <class T>
void PidController<T>::setTolerance(T tolerance)
{
	_tolerance = tolerance;
};

template <class T>
float PidController<T>::getProportionalGain(void)
{
	return _proportionalGain;
};

template <class T>
void PidController<T>::setProportionalGain(float proportionalGain)
{
	_proportionalGain = proportionalGain;
};

template <class T>
float PidController<T>::getIntegralGain(void)
{
	return _integralGain;
};

template <class T>
void PidController<T>::setIntegralGain(float integralGain)
{
	_integralGain = integralGain;
};

template <class T>
float PidController<T>::getDerivativeGain(void)
{
	return _derivativeGain;
};

template <class T>
void PidController<T>::setDerivativeGain(float derivativeGain)
{
	_derivativeGain = derivativeGain;
};

template <class T>
T PidController<T>::getLastError(void)
{
	return _lastError;
};

template <class T>
T PidController<T>::getLastResult(void)
{
	return _lastResult;
};

template <class T>
unsigned long PidController<T>::getLastTime(void)
{
	return _lastTime;
};

template <class T>
T PidController<T>::calculate(T value)
{
	T result = (T)0;
	T error = value - _targetValue;
	unsigned long time = millis();
	long dt = time - _lastTime;
	
	if (dt < _sampleTime || abs(error) < _tolerance)
	{
		return _lastResult;
	}

	// Calculate proportional term?
	if (TERM_PROPORTIONAL & _terms)
	{
		result += error*_proportionalGain;
	}
	// Calculate integral term?
	if (TERM_INTEGRAL & _terms)
	{
		result += (error + _lastError)*dt*_integralGain;
	}
	// Calculate derivative term?
	if (TERM_DERIVATIVE & _terms)
	{
		result += (error - _lastError)/dt*_derivativeGain;
	}

	_lastError = error;
	_lastResult = result;
	_lastTime = time;

	return result;
};

template class PidController<char>;
template class PidController<int>;
template class PidController<long>;
template class PidController<long long>;
template class PidController<float>;
template class PidController<double>;

