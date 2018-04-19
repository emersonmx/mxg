#ifndef MXG_TIME_HPP_
#define MXG_TIME_HPP_

#include <cstdint>

namespace mxg {

class Time {
public:
    Time();

    float asSeconds() const;
    int32_t asMilliseconds() const;
    int64_t asMicroseconds() const;

private:
    friend Time seconds(const float amount);
    friend Time milliseconds(const int32_t amount);
    friend Time microseconds(const int64_t amount);

    explicit Time(const int64_t microseconds);

    int64_t microseconds_;
};

Time seconds(const float amount);
Time milliseconds(const int32_t amount);
Time microseconds(const int64_t amount);

bool operator ==(const Time& left, const Time& right);
bool operator !=(const Time& left, const Time& right);
bool operator <(const Time& left, const Time& right);
bool operator >(const Time& left, const Time& right);
bool operator <=(const Time& left, const Time& right);
bool operator >=(const Time& left, const Time& right);
Time operator -(const Time& right);
Time operator +(const Time& left, const Time& right);
Time& operator +=(Time& left, const Time& right);
Time operator -(const Time& left, const Time& right);
Time& operator -=(Time& left, const Time& right);
Time operator *(const Time& left, const float right);
Time operator *(const Time& left, const int64_t right);
Time operator *(const float left, const Time& right);
Time operator *(const int64_t left, const Time& right);
Time& operator *=(Time& left, const float right);
Time& operator *=(Time& left, const int64_t right);
Time operator /(const Time& left, const float right);
Time operator /(const Time& left, const int64_t right);
Time& operator /=(Time& left, const float right);
Time& operator /=(Time& left, const int64_t right);
float operator /(const Time& left, const Time& right);
Time operator %(const Time& left, const Time& right);
Time& operator %=(Time& left, const Time& right);

} /* namespace mxg */
#endif /* MXG_TIME_HPP_ */
