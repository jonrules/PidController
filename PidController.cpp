#include <PidController.h>
#include <Arduino.h>

template <class T>
PidController<T>::PidController(T targetValue, unsigned char length, unsigned char terms)
{
	_targetValue = targetValue;
	_length = length;
	_terms = terms;
	_values = new T[length];
	_timeValues = new unsigned long[length];
};

template <class T>
PidController<T>::~PidController(void)
{
	delete [] _values;
	delete [] _timeValues;
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
unsigned long *PidController<T>::getTimeValues(void)
{
	return _timeValues;
};

template <class T>
void PidController<T>::addValue(T value)
{
	_values[_currentIndex] = value - _targetValue;
	_timeValues[_currentIndex] = millis();
	_currentIndex = (_currentIndex + 1) % _length;
};

template <class T>
T PidController<T>::calculate()
{
	T result = (T)0;
	unsigned long dt;

	// Calculate proportional term?
	if (TERM_PROPORTIONAL & _terms)
	{
		result += _values[(_currentIndex + _length - 1) % _length]*_proportionalGain;
	}

	if ((TERM_INTEGRAL | TERM_DERIVATIVE) & _terms)
	{
		for (unsigned char i = _currentIndex, j = (_currentIndex + 1) % _length, n = 0; 
				n < _length - 1; 
				i = j, j = (j + 1) % _length, n++)
		{
			// Calculate differences
			dt = _timeValues[j] - _timeValues[i];
			if (dt > 0)
			{
				// Calculate integral term?
				if (TERM_INTEGRAL & _terms)
				{
					result += (_values[j] + _values[i])*dt*_integralGain/2;
				}
				// Calculate derivative term?
				if (TERM_DERIVATIVE & _terms)
				{
					result += (_values[j] - _values[i])/dt*_derivativeGain;
				}
			}
		}
	}

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

