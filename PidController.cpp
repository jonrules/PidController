#include <PidController.h>

PidController::PidController(T targetValue, unsigned char length, unsigned char terms = 0xff)
{
	_targetValue = targetValue;
	_length = length;
	_terms = terms;
	_values = new T[length];
};

PidController::~PidController(void)
{
	delete [] _values;
};

unsigned char PidController::getTerms()
{
	return _terms;
};

void PidController::setTerms(unsigned char terms)
{
	_terms = terms;
};

float PidController::getProportionalGain(void)
{
	return _proportionalGain;
};

void PidController::setProportionalGain(float proportionalGain)
{
	_proportionalGain = proportionalGain;
};

float PidController::getIntegralGain(void)
{
	return _integralGain;
};

void PidController::setIntegralGain(float integralGain)
{
	_integralGain = integralGain;
};

float PidController::getDerivativeGain(void)
{
	return _derivativeGain;
};

void PidController::setDerivativeGain(float derivativeGain)
{
	_derivativeGain = derivativeGain;
};

void PidController::addValue(T value)
{
	
};

T PidController::calculate()
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

T PidController::calculateProportional()
{
	T result = (T)0;

	return result;
};

T PidController::calculateIntegral()
{
	T result = (T)0;

	return result;
};

T PidController::calculateDerivative()
{
	T result = (T)0;

	return result;
};

