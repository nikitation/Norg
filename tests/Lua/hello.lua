function num_is(value)
    return value*value
end

num = num_is(4)

table = {
    var_string = "some text",
    var_bool = false
}

function RunCFunction(a, b)
    c = HostFunction(a + b)
    return c
end
