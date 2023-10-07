#include "roaring/roaring.h"

/**
 * An example program using the Roaring bitmap C implementation: CRoaring.
 */
int main() {
    // We're going to create a couple of bitmaps and merge them together.
    roaring_bitmap_t *bitmap1, *bitmap2;

    // Create the bitmaps with a few initial values. Note that we are using values that yield a sparse bitmap. There
    // are large gaps between the values. This is done on purpose to demonstrate the compression capabilities of
    // roaring bitmaps.
    {
        bitmap1 = roaring_bitmap_create();
        roaring_bitmap_add_many(bitmap1, 3, (uint32_t[]) {1, 50, 300});
        bitmap2 = roaring_bitmap_create();
        roaring_bitmap_add_many(bitmap2, 3, (uint32_t[]) {20, 300, 1000});
    }

    // Merge the bitmaps
    roaring_bitmap_or_inplace(bitmap1, bitmap2);

    // The inplace operation modified bitmap1, let's print it and see the effect of the union.
    printf("'On' bits: ");
    roaring_bitmap_printf(bitmap1);
    printf("\n");

    // The bitmap "cardinality" expresses the number of values stored in the bitmap. It should be 5, which is the number
    // of distinct values initialized in the two bitmaps. 300 was the only value in both bitmaps.
    printf("Cardinality = %d\n", (int) roaring_bitmap_get_cardinality(bitmap1));

    // A main advantage of roaring bitmaps is that they are compressed. Notice how the numeric range of the
    // values in the bitmaps is large (1 to 1,000) but the actual number of bits used by the bitmap is small (when I ran
    // it, it was 26 bytes).
    printf("Size in bytes = %d\n", (int) roaring_bitmap_portable_size_in_bytes(bitmap1));

    // Cleanup
    roaring_bitmap_free(bitmap1);
    roaring_bitmap_free(bitmap2);

    return 0;
}

