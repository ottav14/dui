<script lang="ts">
    import { onMount } from 'svelte';
    import Text from './Text.svelte';

    export let text: string = '';
    export let disabled: boolean = false;
    export let leftBorder: boolean = true;
    export let rightBorder: boolean = true;
    export let topBorder: boolean = true;
    export let bottomBorder: boolean = true;
    export let border: boolean = true;
    export let icon: string = '';
    export let iconSize: number = 24;
    export let primaryColor: string = '#101010';
    export let secondaryColor: string = '#ededed';
    export let tertiaryColor: string = '#515151';
    export let margin: number = 0;
    export let width: string = 'auto';
    export let justify: string = 'center';
    export let onClick: () => void = () => {};
    export let type: string = 'default';

    let textColor = secondaryColor;

    switch(type) {
        case 'plus':
            text = '+';
            width = '6rem';
            break;
        case 'minus':
            text = '-';
            width = '6rem';
            break;
    }

    let hovered = false;
    let ref: HTMLButtonElement;

    if(!border) {
        leftBorder = false;
        rightBorder = false;
        topBorder = false;
        bottomBorder = false;
    }

    $: {
        if(disabled) textColor = tertiaryColor;
        else if(hovered) textColor = primaryColor;
        else textColor = secondaryColor;
    }

    onMount(() => {
        ref.addEventListener('mouseenter', () => hovered = true);
        ref.addEventListener('mouseleave', () => hovered = false);
    });
</script>

<button 
    disabled={disabled} 
    on:click={onClick}
    bind:this={ref}
    style={`
        --primary: ${primaryColor};
        --secondary: ${secondaryColor};
        border-left: ${leftBorder ? `1px solid ${secondaryColor}` : 'none'};
        border-right: ${rightBorder ? `1px solid ${secondaryColor}` : 'none'};
        border-top: ${topBorder ? `1px solid ${secondaryColor}` : 'none'};
        border-bottom: ${bottomBorder ? `1px solid ${secondaryColor}` : 'none'};
        margin: ${margin}rem;
        width: ${width};
        max-width: ${width};
        justify-content: ${justify};
    `}
>
    <Text text={text} color={textColor} />
    {#if icon.length > 0}
        <svg 
            xmlns="http://www.w3.org/2000/svg" 
            width={`${iconSize}px`} 
            height={`${iconSize}px`} 
            viewBox="0 -960 960 960" 
            fill={secondaryColor}
            stroke={secondaryColor}
        >
            <path d={icon}/>
        </svg>
    {/if}

</button>

<style>
    button {
        display: flex;
        align-items: center;
        text-align: center;
        min-width: 6rem;
        min-height: 6rem;
        padding: 1.5rem;
        border-radius: 0;
        background-color: var(--primary, #101010);
        color: var(--secondary, #ededed);
        font-size: 24pt;
        transition: all 0.15s ease;
        cursor: pointer; 
    }

    button:hover {
        background-color: var(--secondary, #ededed);
        color: var(--primary, #101010);
        transform: scale(1.1);
        z-index: 2;
    }

    button:disabled {
        background-color: var(--tertiary, #101010);
        color: var(--neutral, #424242);
        cursor: not-allowed;
        transform: scale(1);
    }

    button:active:not(:disabled) {
        transform: scale(1.15);
    }

    button:hover svg {
        fill: var(--primary);
        stroke: var(--primary);
    }
</style>
