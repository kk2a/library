#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../string/static_rolling_hash.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;

void test_basic_and_edge_cases() {
    // Test basic constructor and get operations
    string s = "hello";
    kk2::SRoliha rh(s);
    assert(rh.size() == 5);
    
    // Test single point get
    auto h_first = rh.get(0);
    auto h_second = rh.get(1);
    assert(h_first != h_second); // 'h' != 'e'
    assert(h_first == kk2::SRoliha::H('h'));
    assert(h_second == kk2::SRoliha::H('e'));
    
    // Test empty range
    auto h_empty = rh.get(2, 2);
    assert(h_empty == kk2::SRoliha::H(0));
    
    // Test single character constructor
    kk2::SRoliha rh_char(65); // 'A'
    assert(rh_char.size() == 1);
    assert(rh_char.get(0) == kk2::SRoliha::H(65)); // single point get
    
    // Test vector constructor
    vector<int> v = {1, 2, 3, 4, 5};
    kk2::SRoliha rh_vec(v);
    assert(rh_vec.size() == 5);
    assert(rh_vec.get(0) == kk2::SRoliha::H(1));
    assert(rh_vec.get(4) == kk2::SRoliha::H(5));
    
    // Test empty string
    string empty = "";
    kk2::SRoliha rh_empty(empty);
    assert(rh_empty.size() == 0);
    
    // Test default constructor
    kk2::SRoliha rh_default;
    assert(rh_default.size() == 0);
    
    // Test empty vector
    vector<int> empty_vec;
    kk2::SRoliha rh_empty_vec(empty_vec);
    assert(rh_empty_vec.size() == 0);
    
    // Test basic LCP
    string s1 = "abcdef", s2 = "abcxyz";
    kk2::SRoliha rh1(s1), rh2(s2);
    assert(kk2::SRoliha::lcp(rh1, 0, 6, rh2, 0, 6) == 3); // "abc" common prefix
    
    // Test LCP with empty ranges
    assert(kk2::SRoliha::lcp(rh1, 0, 0, rh2, 0, 0) == 0);
    assert(kk2::SRoliha::lcp(rh1, 0, 3, rh2, 0, 0) == 0);
    assert(kk2::SRoliha::lcp(rh_empty, 0, 0, rh1, 0, 3) == 0);
    
    // Test basic strcmp
    string s3 = "abc", s4 = "abd";
    kk2::SRoliha rh3(s3), rh4(s4);
    assert(kk2::SRoliha::strcmp(rh3, 0, 3, rh4, 0, 3) == -1); // abc < abd
    
    // Test strcmp edge cases
    assert(kk2::SRoliha::strcmp(rh3, 0, 0, rh4, 0, 0) == 0); // empty == empty
    assert(kk2::SRoliha::strcmp(rh3, 0, 0, rh4, 0, 3) == -1); // empty < non-empty
    assert(kk2::SRoliha::strcmp(rh3, 0, 3, rh4, 0, 0) == 1); // non-empty > empty
    assert(kk2::SRoliha::strcmp(rh3, 0, 3, rh3, 0, 3) == 0); // same == same
    
    // Test basic merge
    string s5 = "hello", s6 = "world", s7 = "helloworld";
    kk2::SRoliha rh5(s5), rh6(s6), rh7(s7);
    auto merged = kk2::SRoliha::merge(rh5, rh6);
    assert(merged.size() == 10);
    assert(merged.get(0, 10) == rh7.get(0, 10)); // merged hash equals direct construction
    
    // Test merge with empty
    auto merged_empty1 = kk2::SRoliha::merge(rh_empty, rh5);
    assert(merged_empty1.size() == 5);
    assert(merged_empty1.get(0, 5) == rh5.get(0, 5));
    
    auto merged_empty2 = kk2::SRoliha::merge(rh5, rh_empty);
    assert(merged_empty2.size() == 5);
    assert(merged_empty2.get(0, 5) == rh5.get(0, 5));
    
    // Test numerical sequence
    vector<int> nums = {1, 2, 3, 2, 1};
    kk2::SRoliha rh_nums(nums);
    assert(rh_nums.get(0) == rh_nums.get(4)); // single point palindrome
    assert(rh_nums.get(1) == rh_nums.get(3)); // single point palindrome
    
    // Test large values
    vector<int> large_nums = {1000000, 999999, 1000001};
    kk2::SRoliha rh_large(large_nums);
    assert(rh_large.size() == 3);
    assert(rh_large.get(0) == kk2::SRoliha::H(1000000));
}
void test_random_comprehensive() {
    // Test random strings with all operations
    rep(2000) {
        int len1 = kk2::random::rng(1, 101);
        int len2 = kk2::random::rng(1, 101);
        
        string s1, s2;
        rep(len1) s1 += char('a' + kk2::random::rng(0, 26));
        rep(len2) s2 += char('a' + kk2::random::rng(0, 26));
        
        kk2::SRoliha rh1(s1);
        kk2::SRoliha rh2(s2);
        
        assert(rh1.size() == len1);
        assert(rh2.size() == len2);
        
        // Test single point get
        if (len1 > 0) {
            int idx1 = kk2::random::rng(0, len1);
            assert(rh1.get(idx1) == kk2::SRoliha::H(s1[idx1]));
        }
        if (len2 > 0) {
            int idx2 = kk2::random::rng(0, len2);
            assert(rh2.get(idx2) == kk2::SRoliha::H(s2[idx2]));
        }
        
        // Test substring operations
        int l1 = kk2::random::rng(0, len1);
        int r1 = kk2::random::rng(l1, len1 + 1);
        int l2 = kk2::random::rng(0, len2);
        int r2 = kk2::random::rng(l2, len2 + 1);
        
        auto h1 = rh1.get(l1, r1);
        
        // Verify substring hash consistency
        if (l1 < r1) {
            string sub1 = s1.substr(l1, r1 - l1);
            kk2::SRoliha rh_sub1(sub1);
            assert(h1 == rh_sub1.get(0, r1 - l1));
        }
        
        // Test LCP
        int lcp_len = kk2::SRoliha::lcp(rh1, l1, r1, rh2, l2, r2);
        int expected_lcp = 0;
        int min_len = min(r1 - l1, r2 - l2);
        for (int i = 0; i < min_len; i++) {
            if (l1 + i < len1 && l2 + i < len2 && s1[l1 + i] == s2[l2 + i]) {
                expected_lcp++;
            } else {
                break;
            }
        }
        assert(lcp_len == expected_lcp);
        
        // Test strcmp
        int cmp_result = kk2::SRoliha::strcmp(rh1, l1, r1, rh2, l2, r2);
        string sub1 = s1.substr(l1, r1 - l1);
        string sub2 = s2.substr(l2, r2 - l2);
        int expected_cmp = (sub1 < sub2) ? -1 : (sub1 > sub2) ? 1 : 0;
        assert(cmp_result == expected_cmp);
        
        // Test hash collision detection
        if (s1 == s2) {
            assert(rh1.get(0, len1) == rh2.get(0, len2));
        } else if (len1 == len2) {
            assert(rh1.get(0, len1) != rh2.get(0, len2));
        }
    }
}
void test_random_merge() {
    // Test merge operation with random strings
    rep(500) {
        int len1 = kk2::random::rng(1, 51);
        int len2 = kk2::random::rng(1, 51);
        
        string s1, s2;
        rep(len1) s1 += char('a' + kk2::random::rng(0, 26));
        rep(len2) s2 += char('a' + kk2::random::rng(0, 26));
        
        kk2::SRoliha rh1(s1);
        kk2::SRoliha rh2(s2);
        
        auto merged = kk2::SRoliha::merge(rh1, rh2);
        assert(merged.size() == len1 + len2);
        
        // Test that merged hash equals direct construction
        string concatenated = s1 + s2;
        kk2::SRoliha rh_direct(concatenated);
        assert(merged.get(0, len1 + len2) == rh_direct.get(0, len1 + len2));
        
        // Test partial hashes
        assert(merged.get(0, len1) == rh1.get(0, len1));
        assert(merged.get(len1, len1 + len2) == rh2.get(0, len2));
        
        // Test single point get on merged
        if (len1 + len2 > 0) {
            int idx = kk2::random::rng(0, len1 + len2);
            assert(merged.get(idx) == rh_direct.get(idx));
            assert(merged.get(idx) == kk2::SRoliha::H(concatenated[idx]));
        }
        
        // Test random substrings of merged
        rep(10) {
            int l = kk2::random::rng(0, len1 + len2);
            int r = kk2::random::rng(l, len1 + len2 + 1);
            
            auto h_merged = merged.get(l, r);
            auto h_direct = rh_direct.get(l, r);
            assert(h_merged == h_direct);
        }
    }
}

// Performance test configuration
struct PerformanceConfig {
    // Test sizes
    static constexpr int LARGE_SIZE = 100000;
    static constexpr int MEDIUM_SIZE = 50000;
    static constexpr int SMALL_SIZE = 10000;
    
    // Test iterations
    static constexpr int MANY_QUERIES = 100000;
    static constexpr int MEDIUM_QUERIES = 50000;
    static constexpr int FEW_QUERIES = 1000;
    
    // Hash collision test settings
    static constexpr int COLLISION_TEST_SIZE = 100000;
    static constexpr int STRING_MAX_LENGTH = 21;
    
    // Value ranges
    static constexpr int ALPHABET_SIZE = 26;
    static constexpr int LARGE_VALUE_RANGE = 1000000;
};

void test_performance() {
    // Large size performance test
    cerr << "Starting StaticRollingHash performance tests..." << endl;
    cerr << "Configuration:" << endl;
    cerr << "  Large size: " << PerformanceConfig::LARGE_SIZE << endl;
    cerr << "  Medium size: " << PerformanceConfig::MEDIUM_SIZE << endl;
    cerr << "  Many queries: " << PerformanceConfig::MANY_QUERIES << endl;
    cerr << "  Medium queries: " << PerformanceConfig::MEDIUM_QUERIES << endl;
    cerr << endl;
    
    // Test 1: Large string construction and substring queries
    {
        int n = PerformanceConfig::LARGE_SIZE;
        string large_str;
        large_str.reserve(n);
        for (int i = 0; i < n; i++) {
            large_str += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
        }
        
        auto start = chrono::high_resolution_clock::now();
        kk2::SRoliha rh(large_str);
        auto end = chrono::high_resolution_clock::now();
        auto construction_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << "Construction time for " << n << " characters: " << construction_time << " microseconds" << endl;
        
        // Test many substring queries
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::MANY_QUERIES; i++) {
            int l = kk2::random::rng(0, n);
            int r = kk2::random::rng(l, n + 1);
            auto h = rh.get(l, r);
            (void)h; // suppress unused variable warning
        }
        end = chrono::high_resolution_clock::now();
        auto query_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::MANY_QUERIES << " substring queries time: " << query_time << " microseconds" << endl;
    }
    
    // Test 2: Large vector construction and queries
    {
        int n = PerformanceConfig::LARGE_SIZE;
        vector<int> large_vec;
        large_vec.reserve(n);
        for (int i = 0; i < n; i++) {
            large_vec.push_back(kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE));
        }
        
        auto start = chrono::high_resolution_clock::now();
        kk2::SRoliha rh(large_vec);
        auto end = chrono::high_resolution_clock::now();
        auto construction_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << "Vector construction time for " << n << " elements: " << construction_time << " microseconds" << endl;
        
        // Test many single point queries
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::MANY_QUERIES; i++) {
            int idx = kk2::random::rng(0, n);
            auto h = rh.get(idx);
            (void)h;
        }
        end = chrono::high_resolution_clock::now();
        auto point_query_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::MANY_QUERIES << " single point queries time: " << point_query_time << " microseconds" << endl;
    }
    
    // Test 3: Many LCP operations
    {
        int n = PerformanceConfig::MEDIUM_SIZE;
        string s1, s2;
        s1.reserve(n);
        s2.reserve(n);
        for (int i = 0; i < n; i++) {
            s1 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
            s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
        }
        
        kk2::SRoliha rh1(s1), rh2(s2);
        
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::MEDIUM_QUERIES; i++) {
            int l1 = kk2::random::rng(0, n);
            int r1 = kk2::random::rng(l1, n + 1);
            int l2 = kk2::random::rng(0, n);
            int r2 = kk2::random::rng(l2, n + 1);
            int lcp_len = kk2::SRoliha::lcp(rh1, l1, r1, rh2, l2, r2);
            (void)lcp_len;
        }
        auto end = chrono::high_resolution_clock::now();
        auto lcp_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::MEDIUM_QUERIES << " LCP operations time: " << lcp_time << " microseconds" << endl;
    }
    
    // Test 4: Many merge operations
    {
        int n = PerformanceConfig::SMALL_SIZE;
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::FEW_QUERIES; i++) {
            int len1 = kk2::random::rng(1, n / 100);
            int len2 = kk2::random::rng(1, n / 100);
            
            string s1, s2;
            s1.reserve(len1);
            s2.reserve(len2);
            for (int j = 0; j < len1; j++) s1 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
            for (int j = 0; j < len2; j++) s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
            
            kk2::SRoliha rh1(s1), rh2(s2);
            auto merged = kk2::SRoliha::merge(rh1, rh2);
            (void)merged;
        }
        auto end = chrono::high_resolution_clock::now();
        auto merge_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::FEW_QUERIES << " merge operations time: " << merge_time << " microseconds" << endl;
    }
    
    // Test 5: strcmp performance
    {
        int n = PerformanceConfig::MEDIUM_SIZE;
        string s1, s2;
        s1.reserve(n);
        s2.reserve(n);
        for (int i = 0; i < n; i++) {
            s1 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
            s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
        }
        
        kk2::SRoliha rh1(s1), rh2(s2);
        
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::MEDIUM_QUERIES; i++) {
            int l1 = kk2::random::rng(0, n);
            int r1 = kk2::random::rng(l1, n + 1);
            int l2 = kk2::random::rng(0, n);
            int r2 = kk2::random::rng(l2, n + 1);
            int cmp_result = kk2::SRoliha::strcmp(rh1, l1, r1, rh2, l2, r2);
            (void)cmp_result;
        }
        auto end = chrono::high_resolution_clock::now();
        auto strcmp_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::MEDIUM_QUERIES << " strcmp operations time: " << strcmp_time << " microseconds" << endl;
    }
    
    cerr << "StaticRollingHash performance tests completed!" << endl;
}

void test() {
    test_basic_and_edge_cases();
    test_random_comprehensive();
    test_random_merge();
    test_performance();
    
    cerr << "All tests passed!" << endl;
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test();

    return 0;
}
