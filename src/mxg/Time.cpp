#include <mxg/Time.hpp>

namespace mxg {

Time::Time() : microseconds_(0) {}

Time::Time(const int64_t microseconds) : microseconds_(microseconds) {}

float Time::asSeconds() const {
    return microseconds_ / 1000000.f;
}

int32_t Time::asMilliseconds() const {
    return static_cast<int32_t>(microseconds_ / 1000);
}

int64_t Time::asMicroseconds() const {
    return microseconds_;
}

Time seconds(const float amount) {
    return Time(static_cast<int64_t>(amount * 1000000));
}

Time milliseconds(const int32_t amount) {
    return Time(static_cast<int64_t>(amount) * 1000);
}

Time microseconds(const int64_t amount) {
    return Time(amount);
}

bool operator ==(const Time& left, const Time& right) {
    return left.asMicroseconds() == right.asMicroseconds();
}

bool operator !=(const Time& left, const Time& right) {
    return left.asMicroseconds() != right.asMicroseconds();
}

bool operator <(const Time& left, const Time& right) {
    return left.asMicroseconds() < right.asMicroseconds();
}

bool operator >(const Time& left, const Time& right) {
    return left.asMicroseconds() > right.asMicroseconds();
}

bool operator <=(const Time& left, const Time& right) {
    return left.asMicroseconds() <= right.asMicroseconds();
}

bool operator >=(const Time& left, const Time& right) {
    return left.asMicroseconds() >= right.asMicroseconds();
}

Time operator -(const Time& right) {
    return microseconds(-right.asMicroseconds());
}

Time operator +(const Time& left, const Time& right) {
    return microseconds(left.asMicroseconds() + right.asMicroseconds());
}

Time& operator +=(Time& left, const Time& right) {
    return left = left + right;
}

Time operator -(const Time& left, const Time& right) {
    return microseconds(left.asMicroseconds() - right.asMicroseconds());
}

Time& operator -=(Time& left, const Time& right) {
    return left = left - right;
}

Time operator *(const Time& left, const float right) {
    return seconds(left.asSeconds() * right);
}

Time operator *(const Time& left, const int64_t right) {
    return microseconds(left.asMicroseconds() * right);
}

Time operator *(const float left, const Time& right) {
    return right * left;
}

Time operator *(const int64_t left, const Time& right) {
    return right * left;
}

Time& operator *=(Time& left, const float right) {
    return left = left * right;
}

Time& operator *=(Time& left, const int64_t right) {
    return left = left * right;
}

Time operator /(const Time& left, float const right) {
    return seconds(left.asSeconds() / right);
}

Time operator /(const Time& left, const int64_t right) {
    return microseconds(left.asMicroseconds() / right);
}

Time& operator /=(Time& left, const float right) {
    return left = left / right;
}

Time& operator /=(Time& left, const int64_t right) {
    return left = left / right;
}

float operator /(const Time& left, const Time& right) {
    return left.asSeconds() / right.asSeconds();
}

Time operator %(const Time& left, const Time& right) {
    return microseconds(left.asMicroseconds() % right.asMicroseconds());
}

Time& operator %=(Time& left, const Time& right) {
    return left = left % right;
}

} /* namespace mxg */
