#include "GlobalVariable.hpp"

// 这个g_pAppService前的APP::不能省略
APP::AppService* APP::g_pAppService {nullptr};
APP::Sequence* APP::g_pSequence {nullptr};
