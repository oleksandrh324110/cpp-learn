#include <benchmark/benchmark.h>

#include "hashmap.h"

static void BM_HashMapInsert(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::hashmap<int, int> map(state.range(0));
    state.ResumeTiming();

    for (int i = 0; i < state.range(0); ++i) {
      map.insert(i, i);
    }
  }
}
BENCHMARK(BM_HashMapInsert)->Range(8, 8 << 8);

static void BM_HashMapRetrieve(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::hashmap<int, int> map(state.range(0));
    for (int i = 0; i < state.range(0); ++i) {
      map.insert(i, i);
    }
    state.ResumeTiming();

    for (int i = 0; i < state.range(0); ++i) {
      benchmark::DoNotOptimize(map.contains(i));
    }
  }
}
BENCHMARK(BM_HashMapRetrieve)->Range(8, 8 << 8);

static void BM_HashMapRemove(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::hashmap<int, int> map(state.range(0));
    for (int i = 0; i < state.range(0); ++i) {
      map.insert(i, i);
    }
    state.ResumeTiming();

    for (int i = 0; i < state.range(0); ++i) {
      map.remove(i);
    }
  }
}
BENCHMARK(BM_HashMapRemove)->Range(8, 8 << 8);

BENCHMARK_MAIN();