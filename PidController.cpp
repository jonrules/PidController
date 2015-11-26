#include <PidController.h>

template <class T>
PidController<T>::PidController(T targetValue, unsigned char length, unsigned char terms)
{
	_targetValue = targetValue;
	_length = length;
	_terms = terms;
	_values = new T[length];
};

template <class T>
PidController<T>::~PidController(void)
{
	delete [] _values;
};

template <class T>
unsigned char PidController<T>::getTerms()
{
	return _terms;
};

template <class T>
void PidController<T>::setTerms(unsigned char terms)
{
	_terms = terms;
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
T *PidController<T>::getValues(void)
{
	return _values;
};

template <class T>
void PidController<T>::addValue(T value)
{
	
};

template <class T>
T PidController<T>::calculate()
{
	T result = (T)0;

	// Calculate proportional term?
	if (TERM_PROPORTIONAL & _terms)
	{
		result += calculateProportional();
	}
	// Calculate integral term?
	if (TERM_INTEGRAL & _terms)
	{
		result += calculateIntegral();
	}
	// Calculate derivative term?
	if (TERM_DERIVATIVE & _terms)
	{
		result += calculateDerivative();
	}

	return result;
};

template <class T>
T PidController<T>::calculateProportional()
{
	T result = (T)0;

	return result;
};

template <class T>
T PidController<T>::calculateIntegral()
{
	T result = (T)0;

	return result;
};

template <class T>
T PidController<T>::calculateDerivative()
{
	T result = (T)0;

	return result;
};

template class PidController<char>;
template class PidController<unsigned char>;
template class PidController<int>;
template class PidController<unsigned int>;
template class PidController<long>;
template class PidController<unsigned long>;
template class PidController<long long>;
template class PidController<unsigned long long>;
template class PidController<float>;
template class PidController<double>;
