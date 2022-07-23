#include <unity.h>
#include "cbuffer.h"
cbuffer_t buff;
void setUp(void)
{
    // set stuff up here

    cbuffer_init(&buff);
}

void tearDown(void)
{
    // clean stuff up here
    cbuffer_clear(&buff);
}

void test_circular_buffer_empty_after_init()
{
    // cbuffer_t buff;

     cbuffer_init(&buff);

    TEST_ASSERT_TRUE(cbuffer_empty(&buff));
}

void test_circular_buffer_not_empty_after_new_element_added()
{
    // cbuffer_t buff;
    // cbuffer_init(&buff);

    cbuffer_add(&buff, 100);

    TEST_ASSERT_FALSE(cbuffer_empty(&buff));
}

void test_circular_buffer_reports_full_correctly()
{
    // cbuffer_t buff;
    // cbuffer_init(&buff);
    for (uint8_t i = 0; i < BUFFER_SIZE; i++)
    {
        cbuffer_add(&buff, i);
    }

    TEST_ASSERT_TRUE(cbuffer_full(&buff));
}

void test_circular_buffer_read_element_succesful()
{
    // cbuffer_t buff;
    // cbuffer_init(&buff);

    uint8_t value = 55;
    cbuffer_add(&buff, value);

    TEST_ASSERT_EQUAL(value, cbuffer_get(&buff));
}

void test_circular_buffer_cleaned_succesfully()
{
    // cbuffer_t buff;
    // cbuffer_init(&buff);

    for (uint8_t i = 0; i < BUFFER_SIZE / 2; i++)
    {
        cbuffer_add(&buff, i);
    }
    cbuffer_clear(&buff);

    TEST_ASSERT_TRUE(cbuffer_empty(&buff));
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_circular_buffer_empty_after_init);
    RUN_TEST(test_circular_buffer_not_empty_after_new_element_added);
    RUN_TEST(test_circular_buffer_reports_full_correctly);
    RUN_TEST(test_circular_buffer_read_element_succesful);
    RUN_TEST(test_circular_buffer_cleaned_succesfully);

    UNITY_END();
}