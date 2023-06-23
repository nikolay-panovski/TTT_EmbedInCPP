SampleItem = {
	charge = 3
	price = 15
}

function SampleItem:ItemEffect(value)
	return value + 2
end