#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../string/dynamic_rolling_hash.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
#include <chrono>
#include <set>
using namespace std;

void test_basic_and_edge_cases() {
    // Test default constructor
    kk2::DRoliha rh_default;
    assert(rh_default.size() == 0);
    
    // Test size constructor
    kk2::DRoliha rh_size(5);
    assert(rh_size.size() == 5);
    
    // Test container constructor with string
    string s = "hello";
    kk2::DRoliha rh_str(s);
    assert(rh_str.size() == 5);
    assert(rh_str.get(0) == kk2::DRoliha::H('h'));
    assert(rh_str.get(4) == kk2::DRoliha::H('o'));
    
    // Test container constructor with vector
    vector<int> v = {1, 2, 3, 4, 5};
    kk2::DRoliha rh_vec(v);
    assert(rh_vec.size() == 5);
    assert(rh_vec.get(0) == kk2::DRoliha::H(1));
    assert(rh_vec.get(4) == kk2::DRoliha::H(5));
    
    // Test empty container
    string empty = "";
    kk2::DRoliha rh_empty(empty);
    assert(rh_empty.size() == 0);
    
    // Test empty vector
    vector<int> empty_vec;
    kk2::DRoliha rh_empty_vec(empty_vec);
    assert(rh_empty_vec.size() == 0);
    
    // Test range get operations
    assert(rh_str.get(0, 5) == rh_str.all_prod());
    assert(rh_str.get(1, 4) != rh_str.get(0, 3));
    assert(rh_str.get(2, 2) == kk2::DRoliha::H(0)); // empty range
    
    // Test single character operations
    kk2::DRoliha rh_single(1);
    rh_single.init_set(0, 'A');
    rh_single.build();
    assert(rh_single.size() == 1);
    assert(rh_single.get(0) == kk2::DRoliha::H('A'));
    assert(rh_single.get(0, 1) == rh_single.all_prod());
}

void test_init_set_and_build() {
    // Test init_set and build workflow
    kk2::DRoliha rh(5);
    
    // Initialize with values
    rh.init_set(0, 'a');
    rh.init_set(1, 'b');
    rh.init_set(2, 'c');
    rh.init_set(3, 'd');
    rh.init_set(4, 'e');
    
    // Build the hash
    rh.build();
    
    // Verify values
    assert(rh.get(0) == kk2::DRoliha::H('a'));
    assert(rh.get(1) == kk2::DRoliha::H('b'));
    assert(rh.get(2) == kk2::DRoliha::H('c'));
    assert(rh.get(3) == kk2::DRoliha::H('d'));
    assert(rh.get(4) == kk2::DRoliha::H('e'));
    
    // Test range operations
    string expected = "abcde";
    kk2::DRoliha rh_expected(expected);
    assert(rh.get(0, 5) == rh_expected.get(0, 5));
    assert(rh.get(1, 4) == rh_expected.get(1, 4));
    assert(rh.all_prod() == rh_expected.all_prod());
}

void test_set_operations() {
    // Test dynamic set operations
    string s = "hello";
    kk2::DRoliha rh(s);
    
    // Change 'h' to 'H'
    rh.set(0, 'H');
    assert(rh.get(0) == kk2::DRoliha::H('H'));
    
    // Verify that the change affected range queries
    string expected = "Hello";
    kk2::DRoliha rh_expected(expected);
    assert(rh.get(0, 5) == rh_expected.get(0, 5));
    assert(rh.all_prod() == rh_expected.all_prod());
    
    // Change multiple characters
    rh.set(1, 'E'); // "HEllo"
    rh.set(4, 'O'); // "HEllO"
    
    assert(rh.get(1) == kk2::DRoliha::H('E'));
    assert(rh.get(4) == kk2::DRoliha::H('O'));
    
    string expected2 = "HEllO";
    kk2::DRoliha rh_expected2(expected2);
    assert(rh.all_prod() == rh_expected2.all_prod());
}

void test_lcp_and_strcmp() {
    // Test LCP operations
    string s1 = "abcdef", s2 = "abcxyz";
    kk2::DRoliha rh1(s1), rh2(s2);
    
    assert(kk2::DRoliha::lcp(rh1, 0, 6, rh2, 0, 6) == 3); // "abc" common prefix
    assert(kk2::DRoliha::lcp(rh1, 1, 6, rh2, 1, 6) == 2); // "bc" common prefix
    assert(kk2::DRoliha::lcp(rh1, 0, 3, rh2, 0, 3) == 3); // "abc" == "abc"
    
    // Test LCP with empty ranges
    assert(kk2::DRoliha::lcp(rh1, 0, 0, rh2, 0, 0) == 0);
    assert(kk2::DRoliha::lcp(rh1, 0, 3, rh2, 0, 0) == 0);
    
    // Test strcmp operations
    string s3 = "abc", s4 = "abd";
    kk2::DRoliha rh3(s3), rh4(s4);
    
    assert(kk2::DRoliha::strcmp(rh3, 0, 3, rh4, 0, 3) == -1); // abc < abd
    assert(kk2::DRoliha::strcmp(rh3, 0, 3, rh3, 0, 3) == 0);  // abc == abc
    assert(kk2::DRoliha::strcmp(rh4, 0, 3, rh3, 0, 3) == 1);  // abd > abc
    
    // Test strcmp edge cases
    assert(kk2::DRoliha::strcmp(rh3, 0, 0, rh4, 0, 0) == 0); // empty == empty
    assert(kk2::DRoliha::strcmp(rh3, 0, 0, rh4, 0, 3) == -1); // empty < non-empty
    assert(kk2::DRoliha::strcmp(rh3, 0, 3, rh4, 0, 0) == 1); // non-empty > empty
}

void test_merge_operations() {
    // Test basic merge
    string s1 = "hello", s2 = "world";
    kk2::DRoliha rh1(s1), rh2(s2);
    
    auto merged = kk2::DRoliha::merge(rh1, rh2);
    assert(merged.size() == 10);
    
    // Verify merged result
    string expected = "helloworld";
    kk2::DRoliha rh_expected(expected);
    assert(merged.all_prod() == rh_expected.all_prod());
    assert(merged.get(0, 10) == rh_expected.get(0, 10));
    
    // Test partial ranges
    assert(merged.get(0, 5) == rh1.get(0, 5));
    assert(merged.get(5, 10) == rh2.get(0, 5));
    
    // Test merge with empty
    kk2::DRoliha rh_empty;
    auto merged_empty1 = kk2::DRoliha::merge(rh_empty, rh1);
    assert(merged_empty1.size() == 5);
    assert(merged_empty1.get(0, 5) == rh1.get(0, 5));
    
    auto merged_empty2 = kk2::DRoliha::merge(rh1, rh_empty);
    assert(merged_empty2.size() == 5);
    assert(merged_empty2.get(0, 5) == rh1.get(0, 5));
}

void test_random_comprehensive() {
    // Test random operations with dynamic updates
    rep(1000) {
        int len = kk2::random::rng(1, 51);
        string s;
        rep(len) s += char('a' + kk2::random::rng(0, 26));
        
        kk2::DRoliha rh(s);
        assert(rh.size() == len);
        
        // Test random single point get
        int idx = kk2::random::rng(0, len);
        assert(rh.get(idx) == kk2::DRoliha::H(s[idx]));
        
        // Test random range get
        int l = kk2::random::rng(0, len);
        int r = kk2::random::rng(l, len + 1);
        
        if (l < r) {
            string sub = s.substr(l, r - l);
            kk2::DRoliha rh_sub(sub);
            assert(rh.get(l, r) == rh_sub.get(0, r - l));
        }
        
        // Test random set operation
        int pos = kk2::random::rng(0, len);
        char new_char = char('a' + kk2::random::rng(0, 26));
        rh.set(pos, new_char);
        assert(rh.get(pos) == kk2::DRoliha::H(new_char));
        
        // Update original string and verify consistency
        s[pos] = new_char;
        kk2::DRoliha rh_updated(s);
        assert(rh.all_prod() == rh_updated.all_prod());
    }
}

void test_random_lcp_strcmp() {
    // Test LCP and strcmp with random strings
    rep(300) {
        int len1 = kk2::random::rng(1, 31);
        int len2 = kk2::random::rng(1, 31);
        
        string s1, s2;
        rep(len1) s1 += char('a' + kk2::random::rng(0, 26));
        rep(len2) s2 += char('a' + kk2::random::rng(0, 26));
        
        kk2::DRoliha rh1(s1), rh2(s2);
        
        // Test LCP
        int l1 = kk2::random::rng(0, len1);
        int r1 = kk2::random::rng(l1, len1 + 1);
        int l2 = kk2::random::rng(0, len2);
        int r2 = kk2::random::rng(l2, len2 + 1);
        
        int lcp_len = kk2::DRoliha::lcp(rh1, l1, r1, rh2, l2, r2);
        
        // Verify LCP manually
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
        int cmp_result = kk2::DRoliha::strcmp(rh1, l1, r1, rh2, l2, r2);
        string sub1 = s1.substr(l1, r1 - l1);
        string sub2 = s2.substr(l2, r2 - l2);
        int expected_cmp = (sub1 < sub2) ? -1 : (sub1 > sub2) ? 1 : 0;
        assert(cmp_result == expected_cmp);
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
    static constexpr int COLLISION_TEST_SIZE = 50000;
    static constexpr int STRING_MAX_LENGTH = 21;
    static constexpr int DYNAMIC_UPDATE_COUNT = 10000;
    
    // Value ranges
    static constexpr int ALPHABET_SIZE = 26;
    static constexpr int LARGE_VALUE_RANGE = 1000000;
};

void test_performance() {
    // Large size performance test for dynamic rolling hash
    cerr << "Starting DynamicRollingHash performance tests..." << endl;
    cerr << "Configuration:" << endl;
    cerr << "  Large size: " << PerformanceConfig::LARGE_SIZE << endl;
    cerr << "  Medium size: " << PerformanceConfig::MEDIUM_SIZE << endl;
    cerr << "  Many queries: " << PerformanceConfig::MANY_QUERIES << endl;
    cerr << "  Medium queries: " << PerformanceConfig::MEDIUM_QUERIES << endl;
    cerr << endl;
    
    // Test 1: Large string construction and query performance
    {
        int n = PerformanceConfig::LARGE_SIZE;
        string large_str;
        large_str.reserve(n);
        for (int i = 0; i < n; i++) {
            large_str += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
        }
        
        auto start = chrono::high_resolution_clock::now();
        kk2::DRoliha rh(large_str);
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
    
    // Test 2: Large size construction and set operations performance
    {
        int n = PerformanceConfig::MEDIUM_SIZE;
        auto start = chrono::high_resolution_clock::now();
        kk2::DRoliha rh(n);
        
        // Initialize with random values
        for (int i = 0; i < n; i++) {
            rh.init_set(i, kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE));
        }
        rh.build();
        auto end = chrono::high_resolution_clock::now();
        auto init_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << "Init_set and build time for " << n << " elements: " << init_time << " microseconds" << endl;
        
        // Test many set operations
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::MANY_QUERIES; i++) {
            int idx = kk2::random::rng(0, n);
            int new_val = kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE);
            rh.set(idx, new_val);
        }
        end = chrono::high_resolution_clock::now();
        auto set_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::MANY_QUERIES << " set operations time: " << set_time << " microseconds" << endl;
    }
    
    // Test 3: Many single point queries performance
    {
        int n = PerformanceConfig::LARGE_SIZE;
        vector<int> large_vec;
        large_vec.reserve(n);
        for (int i = 0; i < n; i++) {
            large_vec.push_back(kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE));
        }
        
        kk2::DRoliha rh(large_vec);
        
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::MANY_QUERIES; i++) {
            int idx = kk2::random::rng(0, n);
            auto h = rh.get(idx);
            (void)h;
        }
        auto end = chrono::high_resolution_clock::now();
        auto point_query_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::MANY_QUERIES << " single point queries time: " << point_query_time << " microseconds" << endl;
    }
    
    // Test 4: LCP operations performance
    {
        int n = PerformanceConfig::MEDIUM_SIZE;
        string s1, s2;
        s1.reserve(n);
        s2.reserve(n);
        for (int i = 0; i < n; i++) {
            s1 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
            s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
        }
        
        kk2::DRoliha rh1(s1), rh2(s2);
        
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::MEDIUM_QUERIES; i++) {
            int l1 = kk2::random::rng(0, n);
            int r1 = kk2::random::rng(l1, n + 1);
            int l2 = kk2::random::rng(0, n);
            int r2 = kk2::random::rng(l2, n + 1);
            int lcp_len = kk2::DRoliha::lcp(rh1, l1, r1, rh2, l2, r2);
            (void)lcp_len;
        }
        auto end = chrono::high_resolution_clock::now();
        auto lcp_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::MEDIUM_QUERIES << " LCP operations time: " << lcp_time << " microseconds" << endl;
    }
    
    // Test 5: Merge operations performance
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
            
            kk2::DRoliha rh1(s1), rh2(s2);
            auto merged = kk2::DRoliha::merge(rh1, rh2);
            (void)merged;
        }
        auto end = chrono::high_resolution_clock::now();
        auto merge_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::FEW_QUERIES << " merge operations time: " << merge_time << " microseconds" << endl;
    }
    
    // Test 6: strcmp performance
    {
        int n = PerformanceConfig::MEDIUM_SIZE;
        string s1, s2;
        s1.reserve(n);
        s2.reserve(n);
        for (int i = 0; i < n; i++) {
            s1 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
            s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
        }
        
        kk2::DRoliha rh1(s1), rh2(s2);
        
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::MEDIUM_QUERIES; i++) {
            int l1 = kk2::random::rng(0, n);
            int r1 = kk2::random::rng(l1, n + 1);
            int l2 = kk2::random::rng(0, n);
            int r2 = kk2::random::rng(l2, n + 1);
            int cmp_result = kk2::DRoliha::strcmp(rh1, l1, r1, rh2, l2, r2);
            (void)cmp_result;
        }
        auto end = chrono::high_resolution_clock::now();
        auto strcmp_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::MEDIUM_QUERIES << " strcmp operations time: " << strcmp_time << " microseconds" << endl;
    }
    
    // Test 7: Dynamic update performance with mixed operations
    {
        int n = PerformanceConfig::MEDIUM_SIZE;
        string s;
        s.reserve(n);
        for (int i = 0; i < n; i++) {
            s += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
        }
        
        kk2::DRoliha rh(s);
        
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::MEDIUM_QUERIES; i++) {
            // Random set operation
            int pos = kk2::random::rng(0, n);
            char new_char = char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
            rh.set(pos, new_char);
            
            // Random query operation
            int l = kk2::random::rng(0, n);
            int r = kk2::random::rng(l, n + 1);
            auto h = rh.get(l, r);
            (void)h;
        }
        auto end = chrono::high_resolution_clock::now();
        auto mixed_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::MEDIUM_QUERIES << " mixed set+query operations time: " << mixed_time << " microseconds" << endl;
    }
    
    // Test 9: all_prod() performance
    {
        int n = PerformanceConfig::LARGE_SIZE;
        string s;
        s.reserve(n);
        for (int i = 0; i < n; i++) {
            s += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));
        }
        
        kk2::DRoliha rh(s);
        
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < PerformanceConfig::MANY_QUERIES; i++) {
            auto h = rh.all_prod();
            (void)h;
        }
        auto end = chrono::high_resolution_clock::now();
        auto all_prod_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cerr << PerformanceConfig::MANY_QUERIES << " all_prod() operations time: " << all_prod_time << " microseconds" << endl;
    }
    
    cerr << "DynamicRollingHash performance tests completed!" << endl;
}

void test() {
    test_basic_and_edge_cases();
    test_init_set_and_build();
    test_set_operations();
    test_lcp_and_strcmp();
    test_merge_operations();
    test_random_comprehensive();
    test_random_lcp_strcmp();
    test_performance();
    
    cerr << "All DynamicRollingHash tests passed!" << endl;
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    test();

    return 0;
}
