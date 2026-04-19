<script lang="ts">
    import Text from './Text.svelte';

	export let min = 0;
	export let max = 100;
	export let value = 50;
    export let primaryColor = '#ededed';
    export let secondaryColor = '#515151';
    export let intervalCount = 5;

	let track: HTMLDivElement;
    let currentInterval = 0;

	function updateValue(clientX: number) {
        const rect = track.getBoundingClientRect();
        let percent = (clientX - rect.left) / rect.width;
        const interval = Math.floor(Math.floor(100*percent) / intervalCount);
        if(interval != currentInterval) {
            currentInterval = interval;

            percent = Math.max(0, Math.min(1, percent));

            value = Math.round(
                min + percent * (max - min)
            );
        }
	}

	function handlePointerDown(e: PointerEvent) {
		updateValue(e.clientX);

		const move = (e: PointerEvent) => {
			updateValue(e.clientX);
		};

		const up = () => {
			window.removeEventListener('pointermove', move);
			window.removeEventListener('pointerup', up);
		};

		window.addEventListener('pointermove', move);
		window.addEventListener('pointerup', up);
	}
</script>

<div 
    class="mainContainer"
    style={`
        --primary: ${primaryColor};
        --secondary: ${secondaryColor};
    `}
>
    <div 
        class="sliderContainer"
        on:pointerdown={handlePointerDown}
        role="button"
        tabindex="0"
    >
        <div
            class="slider"
            bind:this={track}
        >
            <div
                class="fill"
                style="width: {value}%"
            ></div>

            <div
                class="thumb"
                style="left: {value}%"
            ></div>
        </div>
    </div>
    <div class="textContainer">
        <Text color={primaryColor} text={value.toString()} />
    </div>
</div>

<style>
    .mainContainer {
        display: flex;
        justify-content: center;
        align-items: center;
        margin: 1rem;
    }

	.slider {
		position: relative;
		width: 300px;
		height: 1rem;
        background: var(--secondary);
        border-radius: 8px;
	}

    .sliderContainer {
        padding: 1rem;
		cursor: pointer;
        user-select: none;
    }

	.fill {
		position: absolute;
		height: 100%;
        border-radius: 8px;
		background: var(--primary);
        transition: all 0.2s ease;
	}

	.thumb {
		position: absolute;
		top: 50%;
		transform: translate(-50%, -50%);
		width: 2rem;
        height: 2rem;
        border-radius: 50%;
        background: var(--primary);
		cursor: grab;
        transition: 
            width 0.1s ease,
            height 0.1s ease,
            left 0.2s ease;
	}

    .sliderContainer:hover .thumb {
        width: 2.4rem;
        height: 2.4rem;
    }

	.sliderContainer:active .thumb {
		cursor: grabbing;
        width: 2.8rem;
        height: 2.8rem;
	}

    .textContainer {
        display: flex;
        justify-content: center;
        align-items: center;
        border: 1px solid var(--primary);
        font-size: 32pt;
        width: 5rem;
        height: 5rem;
    }
</style>
