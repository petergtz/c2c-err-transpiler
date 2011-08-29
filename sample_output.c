int operation()
{
    int status = SUCCESS;

    int rc = set_up_a(&a);
    if (SUCCESS(rc)) {
        int rc = set_up_b(a, &b);
        if (SUCCESS(rc)) {
            c = set_up_c(b);
            if (SUCCESS(rc)) {
                int rc = do_some_work_with(c);
                if (SUCCESS(rc)) {
                    int rc = do_more_work_with(c);
                    if (SUCCESS(rc)) {
                    } else {
                        status = ERROR_DOING_MORE_WORK;
                    }
                } else {
                    status = ERROR_DOING_SOME_WORK;
                }
                clean_up_c(c);
            } else {
                status = ERROR_C;
            }
            clean_up_b(b);
        } else {
            status = ERROR_B;
        }
        clean_up_a(a);
    } else {
        status = ERROR_A;
    }
    return status;
}
