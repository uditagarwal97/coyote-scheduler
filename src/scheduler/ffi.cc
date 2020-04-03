﻿// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "ffi.h"
#include "scheduler.h"

using namespace coyote;

extern "C" {
    COYOTE_API void* create_scheduler() {
        return new Scheduler();
    }

    COYOTE_API int attach(void* scheduler) {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->attach();
        return error_code.value();
    }

    COYOTE_API int detach(void* scheduler) {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->detach();
        return error_code.value();
    }

    COYOTE_API int create_next_operation(void* scheduler)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->create_next_operation();
        return error_code.value();
    }

    COYOTE_API int start_operation(void* scheduler, size_t operation_id)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->start_operation(operation_id);
        return error_code.value();
    }

    COYOTE_API int complete_operation(void* scheduler, size_t operation_id)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->complete_operation(operation_id);
        return error_code.value();
    }

    COYOTE_API int create_resource(void* scheduler, size_t resource_id)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->create_resource(resource_id);
        return error_code.value();
    }

    COYOTE_API int wait_resource(void* scheduler, size_t resource_id)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->wait_resource(resource_id);
        return error_code.value();
    }

    COYOTE_API int wait_resources(void* scheduler, size_t* resource_ids, int array_size, bool wait_all)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->wait_resources(resource_ids, array_size, wait_all);
        return error_code.value();
    }

    COYOTE_API int signal_resource(void* scheduler, size_t resource_id)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->signal_resource(resource_id);
        return error_code.value();
    }

    COYOTE_API int delete_resource(void* scheduler, size_t resource_id)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->delete_resource(resource_id);
        return error_code.value();
    }

    COYOTE_API int schedule_next_operation(void* scheduler)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->schedule_next_operation();
        return error_code.value();
    }

    COYOTE_API bool get_next_boolean(void* scheduler)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        return ptr->get_next_boolean();
    }

    COYOTE_API int get_next_integer(void* scheduler, size_t max_value)
    {
        Scheduler* ptr = (Scheduler*)scheduler;
        return ptr->get_next_integer(max_value);
    }

    COYOTE_API int get_last_error_code(void* scheduler) {
        Scheduler* ptr = (Scheduler*)scheduler;
        std::error_code error_code = ptr->get_last_error_code();
        return error_code.value();
    }

    COYOTE_API int dispose_scheduler(void* scheduler) {
        try
        {
            Scheduler* ptr = (Scheduler*)scheduler;
            delete ptr;
        }
        catch (...)
        {
            return make_error_code(ErrorCode::Failure).value();
        }
        
        return make_error_code(ErrorCode::Success).value();
    }
}
