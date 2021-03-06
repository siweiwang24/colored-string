/*
RGB colors.
See https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit

Copyright 2020. Siwei Wang.
*/
#include "rgb_color.h"

channel rgb_color::squeeze(color_t original) noexcept {
  return static_cast<channel>(original * rgb_color::CHANNEL_END / 256);
}

rgb_color::rgb_color(channel red_in, channel green_in, channel blue_in)
    : m_red(red_in), m_green(green_in), m_blue(blue_in) {}

rgb_color::rgb_color(color_t red_in, color_t green_in, color_t blue_in)
    : m_red(squeeze(red_in)),
      m_green(squeeze(green_in)),
      m_blue(squeeze(blue_in)) {}

color_t rgb_color::code() const noexcept {
  static constexpr auto offset = 16;
  const auto red = CHANNEL_END * CHANNEL_END * underlying(m_red);
  const auto green = CHANNEL_END * underlying(m_green);
  const auto blue = underlying(m_blue);
  return static_cast<color_t>(offset + red + green + blue);
}

color* rgb_color::clone() const { return new rgb_color(*this); }
