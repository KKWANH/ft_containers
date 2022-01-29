#ifndef						TYPE1_OR_TYPE2_HPP
#define						TYPE1_OR_TYPE2_HPP

namespace					ft
{
	template				<bool isConst, typename isFalse, typename isTrue>
	struct					chooseConst {};

	template				<typename isFalse, typename isTrue>
	struct					chooseConst<false, isFalse, isTrue> { typedef isFalse type; };

	template				<typename isFalse, typename isTrue>
	struct					chooseConst<true, isFalse, isTrue>  { typedef isTrue  type; };
}

#endif