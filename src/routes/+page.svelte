<script>
    import { Button, Text, Dropdown, Slider, Counter, EquationInput } from '../lib/index.ts';
</script>

<main>
    <Text 
        text="The Gallery"
        type="h1"
    />
    <div class="mainContainer">
        <div class="container">
            <Text 
                text="TEXT"
                type="h2"
            />
            <Text 
                text="This text is normal."
            />
            <Text 
                text="This text is a different color."
                color="#4287f5"
            />
            <Text 
                text="This text is a different size."
                fontSize={32}
            />
            <Text 
                text="This text is bold."
                bold={true}
            />
            <Text 
                text="This text is italicized."
                italic={true}
            />
            <div class="paragraphContainer">
                <Text 
                    text={`This is a paragraph of text.
                        It is intentionally long in order to
                        test whether or not line wrapping
                        is functioning properly. There are many
                        words in this paragraph. None of them mean
                        much of anything. They exist for their utility alone.
                        There are no secret messages hidden within this text.
                        Do not for look any. You will be dissapointed.
                    `}
                />
            </div>
        </div>
        <div class="container">
            <Text 
                text="BUTTONS"
                type="h2"
            />
            <Button 
                text="This button has text." 
                margin={2}
            />
            <Button 
                text="This button is a different color." 
                primaryColor="#4287f5"
                border={false}
                margin={2}
            />
            <Button
                text="This button toggles."
                margin={2}
                toggleButton={true}
            />
            <div class="iconContainer">
                <Button 
                    type="plus"
                />
                <Button 
                    type="minus"
                />
                <Button 
                    type="settings"
                />
            </div>
        </div>
        <div class="container">
            <Text 
                text="DROPDOWN"
                type="h2"
            />
            <Dropdown 
                width={24}
            />
            <Dropdown 
                width={24}
                items={[ 'Why not blue?', 'I am blue.', 'da-ba-dee', 'da-ba-di' ]}
                primaryColor="#4287f5"
                border={false}
            />
        </div>
        <div class="container">
            <Text 
                text="SLIDER"
                type="h2"
            />
            <Slider />
            <Slider primaryColor="#4287f5" />
            <Slider 
                value={500}
                min={-50}
                max={1000}
            />
            <Slider 
                value={0.01}
                min={0.001}
                max={0.1}
                increment={0.001}
                decimalDigits={3}
            />
        </div>
        <div class="container">
            <Text 
                text="COUNTER"
                type="h2"
            />
            <Counter />
        </div>
        <div class="container">
            <Text 
                text="EQUATION INPUT"
                type="h2"
            />
            <EquationInput />
        </div>
    </div>
</main>

<style>
    main {
        margin: 2rem;
    }

    .mainContainer {
        display: flex;
        flex-wrap: wrap;
    }

    .container {
        display: flex;
        flex-direction: column;
        padding: 1rem;
        margin: 1rem;
        min-width: 40rem;
        border: 1px solid #ededed;
    }

    .iconContainer {
        display: flex;
        justify-content: space-evenly;
    }

    .paragraphContainer {
        width: 50rem;
    }
</style>
