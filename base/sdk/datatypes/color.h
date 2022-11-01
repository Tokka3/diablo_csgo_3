#pragma once
// used: std::array
#include <array>

enum
{
	COLOR_R = 0,
	COLOR_G = 1,
	COLOR_B = 2,
	COLOR_A = 3
};

struct ColorRGBExp32
{
	std::uint8_t r, g, b;
	char exponent;
};
struct trh {
	float        a = 582;
	float        aeasing = 0.05;

	float        targeta = 0;
	float        ay = 0;

	float        h = 0;
	float        heasing = 0.05;

	float        targeth = 0;
	float        hy = 0;

	int timer = 0;
	float mult;
};
class String {
public:

	int timer = 0;
	std::string str = "";
	bool isClicked = false;
	String(std::string str) {
		this->str = str;
	}
	String() {
		this->str = "";
	}

};

class Color
{
public:
	Color() = default;

	/* default color constructor (in: 0 - 255) */
	  Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255) :
		arrColor({ r, g, b, a }) { }

	  Color(int r, int g, int b, int a = 255) :
		arrColor({ static_cast<std::uint8_t>(r), static_cast<std::uint8_t>(g), static_cast<std::uint8_t>(b), static_cast<std::uint8_t>(a) }) { }

	/* float color constructor (in: 0.0 - 1.0) */
	  Color(float r, float g, float b, float a = 1.0f) :
		arrColor({ static_cast<std::uint8_t>(r * 255.f), static_cast<std::uint8_t>(g * 255.f), static_cast<std::uint8_t>(b * 255.f), static_cast<std::uint8_t>(a * 255.f) }) { }

	/* output color to given variables */
	void Get(std::uint8_t& r, std::uint8_t& g, std::uint8_t& b, std::uint8_t& a) const
	{
		r = arrColor[COLOR_R];
		g = arrColor[COLOR_G];
		b = arrColor[COLOR_B];
		a = arrColor[COLOR_A];
	}

	/* convert color to directx argb */
	[[nodiscard]] D3DCOLOR GetD3D() const
	{
		return D3DCOLOR_ARGB(arrColor[COLOR_A], arrColor[COLOR_R], arrColor[COLOR_G], arrColor[COLOR_B]);
	}
	void SetColour(int r, int g, int b, int a) {
		arrColor = { static_cast<std::uint8_t>(r), static_cast<std::uint8_t>(g), static_cast<std::uint8_t>(b), static_cast<std::uint8_t>(a) };
	}
	void SetR(int val) {
		arrColor[0] = val;
	}
	void SetG(int val) {
		arrColor[1] = val;
	}
	void SetB(int val) {
		arrColor[2] = val;
	}
	void SetA(int val) {
		arrColor[3] = val;
	}
	/* convert color to imgui rgba */
	[[nodiscard]] ImU32 GetU32(const float flAlphaMultiplier = 1.0f) const
	{
		return ImGui::GetColorU32(this->GetVec4(flAlphaMultiplier));
	}

	/* convert color to imgui vector */
	[[nodiscard]] ImVec4 GetVec4(const float flAlphaMultiplier = 1.0f) const
	{
		//if (this->isActive)
		return ImVec4(this->Base<COLOR_R>(), this->Base<COLOR_G>(), this->Base<COLOR_B>(), this->Base<COLOR_A>() * flAlphaMultiplier);
		/*else {
			return ImGui::ColorConvertU32ToFloat4(tempCol);
		}*/
	}

	std::uint8_t& operator[](const std::size_t i)
	{
		return this->arrColor[i];
	}

	const std::uint8_t& operator[](const std::size_t i) const
	{
		return this->arrColor[i];
	}

	bool operator==(const Color& colSecond) const
	{
		return this->arrColor == colSecond.arrColor;
	}

	bool operator!=(const Color& colSecond) const
	{
		return !(operator==(colSecond));
	}

	Color& operator=(const Color& colFrom)
	{
		arrColor[COLOR_R] = colFrom.arrColor[COLOR_R];
		arrColor[COLOR_G] = colFrom.arrColor[COLOR_G];
		arrColor[COLOR_B] = colFrom.arrColor[COLOR_B];
		arrColor[COLOR_A] = colFrom.arrColor[COLOR_A];
		return *this;
	}

	/* returns certain R/G/B/A value */
	template <std::size_t N>
	[[nodiscard]] std::uint8_t Get() const
	{
		static_assert(N >= COLOR_R && N <= COLOR_A, "given index is out of range");
		return arrColor[N];
	}

	/* returns copy of color with changed certain R/G/B/A value to given value */
	template <std::size_t N>
	[[nodiscard]] Color Set(const std::uint8_t nValue) const
	{
		static_assert(N >= COLOR_R && N <= COLOR_A, "given index is out of range");

		Color colCopy = *this;
		colCopy.arrColor[N] = nValue;
		return colCopy;
	}

	/* returns copy of color with multiplied certain R/G/B/A value by given value */
	template <std::size_t N>
	[[nodiscard]] Color Multiplier(const float flValue) const
	{
		static_assert(N >= COLOR_R && N <= COLOR_A, "given index is out of range");

		Color colCopy = *this;
		colCopy.arrColor[N] = static_cast<std::uint8_t>(static_cast<float>(colCopy.arrColor[N]) * flValue);
		return colCopy;
	}

	/* returns copy of color with divided certain R/G/B/A value by given value */
	template <std::size_t N>
	[[nodiscard]] Color Divider(const int iValue) const
	{
		static_assert(N >= COLOR_R && N <= COLOR_A, "given index is out of range");

		Color colCopy = *this;
		colCopy.arrColor[N] /= iValue;
		return colCopy;
	}

	/* returns certain R/G/B/A float value (in: 0 - 255, out: 0.0 - 1.0) */
	template <std::size_t N>
	[[nodiscard]] float Base() const
	{
		static_assert(N >= COLOR_R && N <= COLOR_A, "given index is out of range");
		return arrColor[N] / 255.f;
	}

	/* convert color to float array (in: 0 - 255, out: 0.0 - 1.0) */
	[[nodiscard]] std::array<float, 3U> Base() const
	{
		std::array<float, 3U> arrBaseColor = { };
		arrBaseColor[COLOR_R] = this->Base<COLOR_R>();
		arrBaseColor[COLOR_G] = this->Base<COLOR_G>();
		arrBaseColor[COLOR_B] = this->Base<COLOR_B>();
		return arrBaseColor;
	}

	/* set color from float array (in: 0.0 - 1.0, out: 0 - 255) */
	static Color FromBase3(float arrBase[3])
	{
		return Color(arrBase[0], arrBase[1], arrBase[2]);
	}

	/* convert color to float array w/ alpha (in: 0 - 255, out: 0.0 - 1.0) */
	[[nodiscard]] std::array<float, 4U> BaseAlpha() const
	{
		std::array<float, 4U> arrBaseColor = { };
		arrBaseColor[COLOR_R] = this->Base<COLOR_R>();
		arrBaseColor[COLOR_G] = this->Base<COLOR_G>();
		arrBaseColor[COLOR_B] = this->Base<COLOR_B>();
		arrBaseColor[COLOR_A] = this->Base<COLOR_A>();
		return arrBaseColor;
	}

	/* set color from float array w/ alpha (in: 0.0 - 1.0, out: 0 - 255) */
	static Color FromBase4(float arrBase[4])
	{
		return Color(arrBase[0], arrBase[1], arrBase[2], arrBase[3]);
	}

	[[nodiscard]] float Hue() const
	{
		if (arrColor[COLOR_R] == arrColor[COLOR_G] && arrColor[COLOR_G] == arrColor[COLOR_B])
			return 0.f;

		const float r = this->Base<COLOR_R>();
		const float g = this->Base<COLOR_G>();
		const float b = this->Base<COLOR_B>();

		const float flMax = std::max(r, std::max(g, b)), flMin = std::min(r, std::min(g, b));

		if (flMax == flMin)
			return 0.f;

		const float flDelta = flMax - flMin;
		float flHue = 0.f;

		if (flMax == r)
			flHue = (g - b) / flDelta;
		else if (flMax == g)
			flHue = 2.f + (b - r) / flDelta;
		else if (flMax == b)
			flHue = 4.f + (r - g) / flDelta;

		flHue *= 60.f;

		if (flHue < 0.f)
			flHue += 360.f;

		return flHue / 360.f;
	}
	void DisableColour() {
		tempAlpha = arrColor[COLOR_A];
		arrColor[COLOR_A] = 0;
		tempCol = IM_COL32(arrColor[COLOR_R], arrColor[COLOR_G], arrColor[COLOR_B], tempAlpha);
	}
	void EnableColour() {
		arrColor[COLOR_A] = tempAlpha;
	}

	void ManageColour() {
		if (isActive) {
			this->EnableColour();
		}
		else {
			this->DisableColour();
		}
	}
	[[nodiscard]] float Saturation() const
	{
		const float r = this->Base<COLOR_R>();
		const float g = this->Base<COLOR_G>();
		const float b = this->Base<COLOR_B>();

		const float flMax = std::max(r, std::max(g, b)), flMin = std::min(r, std::min(g, b));
		const float flDelta = flMax - flMin;

		if (flMax == 0.f)
			return flDelta;

		return flDelta / flMax;
	}

	[[nodiscard]] float Brightness() const
	{
		const float r = this->Base<COLOR_R>();
		const float g = this->Base<COLOR_G>();
		const float b = this->Base<COLOR_B>();

		return std::max(r, std::max(g, b));
	}

	/* return RGB color converted from HSB/HSV color */
	static Color FromHSB(float flHue, float flSaturation, float flBrightness, float flAlpha = 1.0f)
	{
		const float h = std::fmodf(flHue, 1.0f) / (60.0f / 360.0f);
		const int i = static_cast<int>(h);
		const float f = h - static_cast<float>(i);
		const float p = flBrightness * (1.0f - flSaturation);
		const float q = flBrightness * (1.0f - flSaturation * f);
		const float t = flBrightness * (1.0f - flSaturation * (1.0f - f));

		float r = 0.0f, g = 0.0f, b = 0.0f;

		switch (i)
		{
		case 0:
			r = flBrightness, g = t, b = p;
			break;
		case 1:
			r = q, g = flBrightness, b = p;
			break;
		case 2:
			r = p, g = flBrightness, b = t;
			break;
		case 3:
			r = p, g = q, b = flBrightness;
			break;
		case 4:
			r = t, g = p, b = flBrightness;
			break;
		case 5:
		default:
			r = flBrightness, g = p, b = q;
			break;
		}

		return Color(r, g, b, flAlpha);
	}
	bool isActive = true;
	bool isClicked = false;
	bool isHeldDown = false;
	bool isHeldDownAlpha = false;
	bool isHeldDownHue = false;
	bool init = false;
	int HueYPos = 0;
	int CircleX = 0;
	int CircleY = 0;
	int AlphaX = 0;
	String r;
	String g;
	String b;
	String hex;
	int hexInt = 0;
	bool copyPasteTab = false;
	int timer = 0;
	float hue = 0;
	ImVec4 temp;
	bool mulClicked = false;
	int alpha;
	trh xa;
	trh ya;
	std::uint8_t tempAlpha = 0;

	ImU32 tempCol;
private:
	std::array<std::uint8_t, 4U> arrColor;
};

class Color2 {
public:

	Color visible;
	Color notVisible;
	Color2(Color a, Color b) {
		this->visible = a;
		this->notVisible = b;
	}
};