#include <benchmark/benchmark.h>

#include <iostream>
#include <vector>

struct Data {
  int n;
  std::vector<int> v;
};

Data getData() {
  Data data;
  return data;
}

Data getStaticData() {
  static Data data;
  return data;
}

Data getInitializedData() {
  Data data{100, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
  return data;
}

Data getStaticInitializedData() {
  static Data data{100, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
  return data;
}

static void BM_getData(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(getData());
  }
}

BENCHMARK(BM_getData);

static void BM_getStaticData(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(getStaticData());
  }
}

BENCHMARK(BM_getStaticData);

static void BM_getInitializedData(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(getInitializedData());
  }
}

BENCHMARK(BM_getInitializedData);

static void BM_getStaticInitializedData(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(getStaticInitializedData());
  }
}

BENCHMARK(BM_getStaticInitializedData);

BENCHMARK_MAIN();
