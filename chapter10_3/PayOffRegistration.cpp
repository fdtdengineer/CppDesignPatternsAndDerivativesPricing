#include "PayOffConstructible.hpp"

// PayOffCall を "call", PayOffPut を "put" という名前で検索できるように登録。
// RegisterCall の変数名自体はダミーなので、RegisterHoge とかにしても動作する。

namespace
{
    PayOffHelper<PayOffCall> RegisterCall("call");
    PayOffHelper<PayOffPut> RegisterPut("put");   
}


