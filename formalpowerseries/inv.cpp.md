---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/enumeration.cpp
    title: combinatorics/enumeration.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/base.cpp
    title: formalpowerseries/base.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: combinatorics/bernoulli.cpp
    title: combinatorics/bernoulli.cpp
  - icon: ':heavy_check_mark:'
    path: combinatorics/partition.cpp
    title: combinatorics/partition.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/div.cpp
    title: formalpowerseries/div.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/exp.cpp
    title: formalpowerseries/exp.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/log.cpp
    title: formalpowerseries/log.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/mod.cpp
    title: formalpowerseries/mod.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/pow.cpp
    title: formalpowerseries/pow.cpp
  - icon: ':heavy_check_mark:'
    path: formalpowerseries/sqrt.cpp
    title: formalpowerseries/sqrt.cpp
  - icon: ':warning:'
    path: includes/formalpowerseries.h
    title: includes/formalpowerseries.h
  - icon: ':heavy_check_mark:'
    path: polynomial/interpolate.cpp
    title: polynomial/interpolate.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/multieval.cpp
    title: polynomial/multieval.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.garner.test.cpp
    title: test/aoj/2985.garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.test.cpp
    title: test/aoj/2985.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3072.test.cpp
    title: test/aoj/3072.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3084.test.cpp
    title: test/aoj/3084.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bernoulli_number.test.cpp
    title: test/yosupo/bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/partition_function.test.cpp
    title: test/yosupo/partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2744.test.cpp
    title: test/yukicoder/2744.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/5633.test.cpp
    title: test/yukicoder/5633.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ formalpowerseries/inv.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../combinatorics/enumeration.cpp\"\n#include\
    \ \"base.cpp\"\n#undef call_from_test\n\n#endif\n//BEGIN CUT HERE\ntemplate<typename\
    \ M>\nvector<M> FormalPowerSeries<M>::inv(Poly as,int deg){\n  assert(as[0]!=M(0));\n\
    \  Poly rs({M(1)/as[0]});\n  for(int i=1;i<deg;i<<=1)\n    rs=pre(sub(add(rs,rs),mul(mul(rs,rs),pre(as,i<<1))),i<<1);\n\
    \  return rs;\n}\n\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - combinatorics/enumeration.cpp
  - formalpowerseries/base.cpp
  isVerificationFile: false
  path: formalpowerseries/inv.cpp
  requiredBy:
  - includes/formalpowerseries.h
  - combinatorics/partition.cpp
  - combinatorics/bernoulli.cpp
  - formalpowerseries/exp.cpp
  - formalpowerseries/mod.cpp
  - formalpowerseries/log.cpp
  - formalpowerseries/sqrt.cpp
  - formalpowerseries/pow.cpp
  - formalpowerseries/div.cpp
  - polynomial/interpolate.cpp
  - polynomial/multieval.cpp
  timestamp: '2021-03-25 09:21:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/5633.test.cpp
  - test/yukicoder/2744.test.cpp
  - test/yosupo/partition_function.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/bernoulli_number.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/aoj/2985.test.cpp
  - test/aoj/2985.garner.test.cpp
  - test/aoj/3072.test.cpp
  - test/aoj/3084.test.cpp
documentation_of: formalpowerseries/inv.cpp
layout: document
redirect_from:
- /library/formalpowerseries/inv.cpp
- /library/formalpowerseries/inv.cpp.html
title: formalpowerseries/inv.cpp
---